#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdio.h> 

// Ast stands for Abstract Syntax Tree

void printAST();
void saveAST();
void loopAndWriteASTIntoFile();

typedef struct treeNode {
    char* value;
    struct treeNode* left;
    struct treeNode* right;
} ast;


ast* newNode(char* operation, ast* leftNode, ast* rightNode) {
    ast* node = (ast*) malloc(sizeof(ast));
    
    node->value = operation;
    node->left = leftNode;
    node->right = rightNode;
    return node;
}


ast* newLeaf(char* value) {
    ast* node = (ast*) malloc(sizeof(ast));
   
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printAST(ast* tree) { 
     if (tree == NULL) 
          return; 
  
     /* first recur on left child */
     printAST(tree->left); 
  
     /* then print the data of node */
     printf("%s ", tree->value);   
  
     /* now recur on right child */
     printAST(tree->right); 
} 


void saveAST(ast* tree) {
    FILE *file = fopen("intermedia.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    loopAndWriteASTIntoFile(tree, file);
    fclose(file);
}


void loopAndWriteASTIntoFile(ast* tree, FILE* file) { 
     if (tree == NULL) 
          return; 
  
     /* first recur on left child */
     printAST(tree->left); 
  
     /* then print the data of node */
     fprintf(file, "%s ", tree->value);   
  
     /* now recur on right child */
     printAST(tree->right); 
}

