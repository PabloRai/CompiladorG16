#include <stdlib.h>
#include <string.h>

typedef struct listSymbol {
    char* name;
    char* type;
    char* value;
    int length;
    struct listSymbol* next;
  } symbolNode;



symbolNode* symbolTable;
symbolNode* insert();
symbolNode* findSymbol();
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
        printf("%s\n", current->value);
        current = current->next;
    }
    
}



