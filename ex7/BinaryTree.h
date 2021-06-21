

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "utils.h"
#include "client.h"


/*this tree has just two nodes:
//               node
//              /   \
               v     v
            *left    *right
            /   \     /   \
           v    v     v    v
       *left *right  *left *right

//               n1(11)
//              /   \
               v     v
            n2(12)   n3(13)
            /   \     
           v    v     
        n4(14) n5(15)        

*/
typedef struct Node{
    void* value;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Tree {
	Node* root;
	int elementCount;
}Tree;

typedef struct List_Node{
    void* value;
    struct List_Node *next;
}List_Node;

typedef struct Linked_List {
	List_Node* head;
	int elementCount;
}Linked_List;


Tree* createTree();
int addNewNode(Tree* tree,void (*create_obj)(Node*),unsigned int (*compare)(Node*,Node*));
void printtree_rec(Node *root, int level,void (*print_obj)(Node*,int));
void printtabs(int numtabs);
int removeNode(Tree* tree, Node* parent, Node* toRemove,unsigned int (*compare)(Node*,Node*));
void freeTree(Node* node,void (*freeObjAttr)(Node*));
//void findNode(Tree* tree, List_Node *head,void (*findObj)(Tree*,List_Node*, int*, Date*));
#endif