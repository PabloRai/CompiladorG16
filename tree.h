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

ast* getCopy();


ast* newNode(char* operation, ast* leftNode, ast* rightNode) {
   
    ast* node = (ast*) malloc(sizeof(ast));
    
    ast* leftNodeCopy = getCopy(leftNode);
    ast* rightNodeCopy = getCopy(rightNode);
    
    
    node->value = operation;
    node->left = leftNodeCopy;
    node->right = rightNodeCopy;
    printf("\n  NODO: %s LEFT: %s RIGHT: %s \n", operation, node->left->value, node->right->value);
    
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


ast* getCopy(ast* node) {
    if (node == NULL) {
        return NULL;
    }
    
    ast* nodeCopy = (ast*) malloc(sizeof(ast));
    nodeCopy->value = strdup(node->value);
    nodeCopy->left = node->left;
    nodeCopy->right = node->right;
    return nodeCopy;
}

