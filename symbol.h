#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

typedef struct listSymbol {
    char name[120];
    char* type;
    char* value;
    int length;
    struct listSymbol* next;
  } symbolNode;



symbolNode* symbolTable;
symbolNode* insert();
symbolNode* findSymbol();
void concatenate();
void removeChar();
void printTable();




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
    }
    
    if (isConstant == 1) {
        node->name[0] = '_' ;
        concatenate(node->name, valueToInsert);
        printf("\nAsi quedo %s\n", node->name);
    } else {
        strcpy(node->name, valueToInsert);
    }

    
    node->value = valueToInsert;
    node->next = symbolTable;
    symbolTable = node;
    return node;
}

symbolNode* findSymbol(char* value) {
    symbolNode* tableNode = symbolTable;
    
    while(tableNode != NULL){
        if (strcmp(value, tableNode->value) == 0) {
            return tableNode;
        }
        tableNode = tableNode->next;
    }
    return NULL;
}


void printTable() {
    symbolNode* current = symbolTable;
    printf("\n TABLITA \n");
    while(current != NULL){
        printf("%s %s %d\n", current->value, current->name, current->length);
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