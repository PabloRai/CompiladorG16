#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdio.h> 
#include "symbol.h"
#include "tree.h"


FILE *file;

void generateAssembler();
void initASsembler();
void insertSymbolsOnData();
void insertInitialCodeBlock();

void generateAssembler() {
    file = fopen("final.asm", "w");
    initASsembler();
    insertSymbolsOnData();
    insertInitialCodeBlock();
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


void insertInitialCodeBlock() {
    fprintf(file,"\n\n");
    fprintf(file,".code\n");
    
    fprintf(file,"\tbegin: .startup\n");
    
    fprintf(file,"\tmov AX,@DATA\n");
    fprintf(file,"\tmov DS,AX\n");
    fprintf(file,"\tmov ES,AX\n");
    fprintf(file,"\tfinit\n");
}