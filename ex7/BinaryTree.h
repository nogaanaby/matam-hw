

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "utils.h"


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
} Tree;


Tree* createTree();
int addNewNode(Tree* tree,void (*create_obj)(Node*),bool (*orderBy)(Node*,Node*));
void printtree_rec(Node *root, int level,void (*print_obj)(Node*,int));
void printtabs(int numtabs);


#endif