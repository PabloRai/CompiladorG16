#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdio.h> 

// Ast stands for Abstract Syntax Tree

void printAST();

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


ast* newLeaf(char* symbol) {
    ast* node = (ast*) malloc(sizeof(ast));
    
    node->value = symbol;
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

