#ifdef BINARY_TREE_H
#define BINARY_TREE_H 

#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node {
  int* key;
  struct Node* left;
  struct Node* right;
} Node;

/* create binary tree wite keys */
Node* create_binary_tree(); 
/* return 1 if true  0 if false */
int isOrderTree(Node* head);
void insert_to_tree(Node* head,Node* new_node);
void print_tree(Node* haed); 

#endif