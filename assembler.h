#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdio.h> 
#include "symbol.h"
#include "tree.h"


FILE *file;
int ifLabelCount;
int useSameIfLabel = 0;
int orWasHere = 0;


struct StackForStatements { 
    int top; 
    int* array; 
}; 

struct StackForOperators { 
    int top; 
    char array[5000][300]; 
}; 

struct StackForStatements* stack;
struct StackForOperators* stackOperators;

void generateAssembler(ast tree);
void initASsembler();
void insertSymbolsOnData();
void insertInitialCodeBlock();
void postOrder(ast* tree);
void processNode(ast* tree);
void stackCleanup();
void insertAuxiliarsOperands();
void pushOnStack();
int pop();
void push(int item);
char* popOperator();
void pushOperator(char* item);

void generateAssembler(ast tree) {
    file = fopen("final.asm", "w");
    ifLabelCount = 0;
    stack = (struct StackForStatements*) malloc(sizeof(struct StackForStatements)); 
    stack->array = (int*) malloc(5000* sizeof(int)); 
    stackOperators = (struct StackForOperators*) malloc(sizeof(struct StackForOperators)); 
    initASsembler();
    insertSymbolsOnData();
    insertAuxiliarsOperands();
    insertInitialCodeBlock();
    postOrder(&tree);
    fclose(file);

}




void initASsembler() {
    fprintf(file,"include  macros2.asm \n");
    fprintf(file,"include  number.asm\n\n\n");
    fprintf(file,".MODEL LARGE\n");
    fprintf(file,".386\n");
    fprintf(file,".STACK 200h\n\n");
    fprintf(file,"MAXTEXTSIZE equ 40\n\n");
    fprintf(file,".DATA\n");
}

void insertSymbolsOnData() {
    symbolNode* current = symbolTable;
    while(current != NULL) {
        
        if (strcmp(current->type, "INT") == 0 || strcmp(current->type, "FLOAT") == 0) {
            fprintf(file,"\t%s dd ?\n", current->name);
        }

        if (strcmp(current->type, "STRING") == 0) {
           fprintf(file,"\t%s db MAXTEXTSIZE dup (?),'$'\n", current->name);
        }

        if (strcmp(current->type, "INTEGER_C") == 0) {
            fprintf(file,"\t%s dd %s.0\n", current->name, current->value);
        }

        if (strcmp(current->type, "FLOAT_C") == 0) {
            fprintf(file,"\t%s dd %s\n", current->name, current->value);
        }

        if (strcmp(current->type, "STRING_C") == 0) {
            fprintf(file,"\t%s db %s,'$', %d dup (?)\n", current->name, current->value, current->length);
        }
        
        current = current->next;
    }
    
}


void insertAuxiliarsOperands() {
    fprintf(file,"\t_SUM dd ?\n");
    fprintf(file,"\t_MINUS dd ?\n");
    fprintf(file,"\t_DIVIDE dd ?\n");
    fprintf(file,"\t_MULTIPLY dd ?\n");

}

void insertInitialCodeBlock() {
    fprintf(file,"\n\n");
    fprintf(file,".code\n");
    
    fprintf(file,"\tbegin: .startup\n");
    
    fprintf(file,"\tmov AX,@DATA\n");
    fprintf(file,"\tmov DS,AX\n");
    fprintf(file,"\tmov ES,AX\n");
    fprintf(file,"\tfinit\n");
}

void postOrder(ast* tree) {
    if (tree == NULL) 
    return; 

    postOrder(tree->left); 
    
    if (strcmp(tree->value, "AND") == 0) {
        char* op = popOperator();
        useSameIfLabel = 1;
        if (strcmp(op, ">=") == 0) {
            fprintf(file, "\n\tJL LABEL_IF_%d\n", ifLabelCount);
        }
        push(ifLabelCount);
        stackCleanup();
    }

    if (strcmp(tree->value, "OR") == 0) {
        char* op = popOperator();
        useSameIfLabel = 0;
        if (strcmp(op, ">=") == 0) {
            fprintf(file, "\n\tJGE LABEL_IF_%d\n", ifLabelCount);
        }
        push(ifLabelCount);
        stackCleanup();
        orWasHere = 1;
    }

    if (strcmp(tree->value, "IF") == 0) {
        char* op = popOperator();
        if (useSameIfLabel != 1) {
            ifLabelCount++;
        } else {
            useSameIfLabel = 0;
        }
        
        if (strcmp(op, ">=") == 0) {
            fprintf(file, "\n\tJL LABEL_IF_%d\n", ifLabelCount);
        }

        if (orWasHere == 1) {
            fprintf(file,"LABEL_IF_%d:\n", pop());
            orWasHere = 0;
        }
        push(ifLabelCount);

        
        
    }

    postOrder(tree->right); 
    printf("%s ", tree->value);
    processNode(tree);
}

void processNode(ast* tree) {
    if (strcmp(tree->value, "=") == 0) {
        fprintf(file,"\n\t; ASIGNACION \n");
        fprintf(file,"\tFLD %s\n", tree->right->value);
        fprintf(file,"\tFSTP %s\n", tree->left->value);
    }

    if (strcmp(tree->value, "+") == 0) {
        fprintf(file,"\n\t; SUMA \n");
        fprintf(file,"\tFLD %s\n", tree->left->value);
        fprintf(file,"\tFLD %s\n", tree->right->value);
        fprintf(file,"\tFADD\n");
        tree->value = "_SUM";
        fprintf(file,"\tFSTP %s\n", tree->value);
        stackCleanup();
    }

    if (strcmp(tree->value, "-") == 0) {
        fprintf(file,"\n\t; RESTA \n");
        fprintf(file,"\tFLD %s\n", tree->left->value);
        fprintf(file,"\tFLD %s\n", tree->right->value);
        fprintf(file,"\tFSUB\n");
        tree->value = "_MINUS";
        fprintf(file,"\tFSTP %s\n", tree->value);
        stackCleanup();
    }

    if (strcmp(tree->value, "*") == 0) {
        fprintf(file,"\n\t; MULTIPLICA \n");
        fprintf(file,"\tFLD %s\n", tree->left->value);
        fprintf(file,"\tFLD %s\n", tree->right->value);
        fprintf(file,"\tFMUL\n");
        tree->value = "_MULTIPLY";
        fprintf(file,"\tFSTP %s\n", tree->value);
        stackCleanup();
    }

    if (strcmp(tree->value, "/") == 0) {
        fprintf(file,"\n\t; DIVIDE \n");
        fprintf(file,"\tFLD %s\n", tree->left->value);
        fprintf(file,"\tFLD %s\n", tree->right->value);
        fprintf(file,"\tFDIV\n");
        tree->value = "_DIVIDE";
        fprintf(file,"\tFSTP %s\n", tree->value);
        stackCleanup();
    }

    if (strcmp(tree->value, ">=") == 0) {
        fprintf(file,"\n\t; => \n");
        fprintf(file,"\tFLD %s\n", tree->left->value);
        fprintf(file,"\tFLD %s\n", tree->right->value);
        fprintf(file,"\tFCOM");
        pushOperator(">=");
    }

    if (strcmp(tree->value, "IF") == 0)
    {
        fprintf(file,"LABEL_IF_%d:\n", pop());
        ifLabelCount++;
        stackCleanup();
    }
    

    
    
}


void stackCleanup() {
     fprintf(file, "\n\t; STACK CLENUP\n"); 
     fprintf(file, "\tFFREE st(0)\n");
     fprintf(file, "\tFFREE st(1)\n");
     fprintf(file, "\tFFREE st(2)\n");
     fprintf(file, "\tFFREE st(3)\n");
     fprintf(file, "\tFFREE st(4)\n");
     fprintf(file, "\tFFREE st(5)\n");
     fprintf(file, "\tFFREE st(6)\n");
     fprintf(file, "\tFFREE st(7)\n");
     fprintf(file, "\n");
}

int pop() { 
    return stack->array[stack->top--]; 
}


void push(int item) { 
    stack->array[++stack->top] = item; 
} 

char* popOperator() { 
    return stackOperators->array[stackOperators->top--]; 
}


void pushOperator(char* item) { 
    strcpy(stackOperators->array[++stackOperators->top],item); 
} 