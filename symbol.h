#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

typedef struct listSymbol {
    char name[220];
    char* type;
    char* value;
    int length;
    struct listSymbol* next;
} symbolNode;


typedef struct symbolIdentifier {
    char *value;
    struct symbolIdentifier* next;
} identifierNode;




// Symbol table prototypes
symbolNode* symbolTable;
symbolNode* insert();
symbolNode* findSymbol();
void putTypeIdentifierOnSymbolTable();
void concatenate();
void removeChar();
void printTable();
void saveTable();
char* substring();

// Symbol Identifier auxiliars
identifierNode* identifierList;
identifierNode* insertIdentifier();
identifierNode* findIdentifier();
void clearIdentifierList();

// Not proud of this..
int alreadyDeclarerdFloatIdentifiers = 0;
int alreadyDeclarerdIntegerIdentifiers = 0;
int alreadyDeclarerdStringIdentifiers = 0;
void checkForAlreadyDeclaredType();
void displayAlreadyDeclaredErrorFor();


symbolNode* insert(char* value) {
    symbolNode* foundNode = findSymbol(value);
    if (foundNode != NULL) {
        return foundNode;
    }
    
    symbolNode* node = (symbolNode*) malloc(sizeof(symbolNode));
    int len = strlen(value);
    char* valueToInsert = malloc(len+1);
    strcpy(valueToInsert, value);
    
    // Is it a string constant?
    int isConstant = 0;
    int shouldApplyBase2Transformation = 0;
    int shouldApplyBase16Transformation = 0;
    if (valueToInsert[0] == '"') {
        removeChar(valueToInsert, '"');
        node->length = strlen(valueToInsert);
        isConstant = 1;
        // Is it a float constant?
    } else if (strchr(valueToInsert, '.') != NULL) {
        isConstant = 1;
        // Is it a integer constant?
    } else if (isdigit(valueToInsert[0]) != 0) {
        isConstant = 1;
        if (valueToInsert[0] == '0') {
            if(valueToInsert[1] == 'b') {
                shouldApplyBase2Transformation = 1;
            } else if (valueToInsert[1] == 'x') {
                shouldApplyBase16Transformation = 1;
            }
        }
        
    }
    
    if (isConstant == 1) {
        node->name[0] = '_' ;
        concatenate(node->name, valueToInsert);
    } else {
        strcpy(node->name, valueToInsert);
    }

    if(shouldApplyBase2Transformation == 1) {
        // TODO: Refactor this, extract behaviour into function..
        char* literalValue = substring(valueToInsert, 3, strlen(valueToInsert));
        int transformedValue = (int) strtol(literalValue, NULL, 2);
        itoa(transformedValue, valueToInsert, 10);
    } else if (shouldApplyBase16Transformation == 1) {
        char* literalValue = substring(valueToInsert, 3, strlen(valueToInsert));
        int transformedValue = (int) strtol(literalValue, NULL, 16);
        itoa(transformedValue, valueToInsert, 10);
    }
    if (isConstant == 1) {
        node->value = valueToInsert;
    }

    node->next = symbolTable;
    symbolTable = node;
    return node;
}

symbolNode* findSymbol(char* value) {
    symbolNode* tableNode = symbolTable;
    
    while(tableNode != NULL){
        if ((tableNode->value != NULL && strcmp(value, tableNode->value) == 0) || (strcmp(value, tableNode->name) == 0)) {
            return tableNode;
        }
        tableNode = tableNode->next;
    }
    return NULL;
}


void printTable() {
    symbolNode* current = symbolTable;
    printf("\n TABLA DE SIMBOLOS \n");
    printf("\nNOMBRE\tTIPODATO\tVALOR\tLONGITUD\n");
    while(current != NULL){
        printf("%s\t%s\t\t%s\t%d\n", current->name, current->type, current->value, current->length);
        current = current->next;
    }
    
}



void concatenate(char* original, char* add) {
  
  while(*original) {
      original++;
   }
     
   while(*add){
      *original = *add;
      add++;
      original++;
   }
   *original = '\0';

}


void removeChar(char *s, int c){ 
  
    int j, n = strlen(s); 
    int i;
    for (i=j=0; i<n; i++) 
       if (s[i] != c) 
          s[j++] = s[i]; 
      
    s[j] = '\0'; 
}


identifierNode* insertIdentifier(char *name) {
    identifierNode* foundNode = findIdentifier(name);
    if (foundNode != NULL) {
        return foundNode;
    }


    identifierNode* node = (identifierNode*) malloc(sizeof(identifierNode));
    int len = strlen(name);
    char* valueToInsert = malloc(len+1);
    strcpy(valueToInsert, name);

    node->value = valueToInsert;
    node->next = identifierList;
    identifierList = node;
    return node;
}



identifierNode* findIdentifier(char* value) {
    identifierNode* identifierNode = identifierList;
    while(identifierNode != NULL) {
        if (strcmp(value, identifierNode->value) == 0) {
            return identifierNode;
        }
        identifierNode = identifierNode->next;
    }
    return NULL;
}



void putTypeIdentifierOnSymbolTable(char* type) {
    checkForAlreadyDeclaredType(type);

    identifierNode* identifierNode = identifierList;
    
    while(identifierNode != NULL) {
        symbolNode* symbol = findSymbol(identifierNode->value);
        // Symbol should never be NULL but just in case..
        if (symbol != NULL) {
            if (symbol->type != NULL) {
                fprintf(stderr, "\n ERROR: Variable %s has been already declared", symbol->name);
                exit(1);
            }
            
            int len = strlen(type);
            char* valueToInsert = malloc(len+1);
            strcpy(valueToInsert, type);
            printf("\n --- PUTING TYPE %s ON SYMBOL %s -- \n", valueToInsert, symbol->name);
            
            symbol->type = valueToInsert;
        }
        
        identifierNode = identifierNode->next;
    }
    clearIdentifierList();
}

void clearIdentifierList() {
    identifierList = NULL;
}



char* substring(char *string, int position, int length)
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
   
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(string+position-1);      
      string++;  
   }
 
   *(pointer+c) = '\0';
 
   return pointer;
}


void checkForAlreadyDeclaredType(char* type) {
    if(strcmp("FLOAT", type) == 0) {
        if(alreadyDeclarerdFloatIdentifiers == 1) {
            displayAlreadyDeclaredErrorFor(type);
        }
        alreadyDeclarerdFloatIdentifiers = 1;
    } else if(strcmp("INT", type) == 0) {
        if(alreadyDeclarerdIntegerIdentifiers == 1) {
            displayAlreadyDeclaredErrorFor(type);
        }
        alreadyDeclarerdIntegerIdentifiers = 1;
    } else if(strcmp("STRING", type) == 0) {
        if(alreadyDeclarerdStringIdentifiers == 1) {
            displayAlreadyDeclaredErrorFor(type);
        }
        alreadyDeclarerdStringIdentifiers = 1;
    }
}


void displayAlreadyDeclaredErrorFor(char* type) {
    fprintf(stderr, "\n ERROR: Variable type %s was already declared, only one is allowed", type);
    exit(1);
}



void saveTable() {
    FILE *file = fopen("ts.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    symbolNode* current = symbolTable;
    fprintf(file, "NOMBRE\tTIPODATO\tVALOR\tLONGITUD\n");
    while(current != NULL){
        fprintf(file, "%s\t%s\t\t%s\t%d\n", current->name, current->type, current->value, current->length);
        current = current->next;
    }
    fclose(file);
}
