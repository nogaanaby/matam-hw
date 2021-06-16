#include "BinaryTree.h"

Tree *createTree(){
    Tree* result = malloc(sizeof(Tree));
    if(result!=NULL){
        result->root = NULL;
        result->elementCount= 0;
    }
    return result;
}

int addNewNode(Tree* tree,void (*create_obj)(Node*)){
    Node* new_node= (Node*) malloc(sizeof(Node));
    Node* current=tree->root;
    create_obj(new_node);
    new_node->left=NULL;
    new_node->right=NULL;
    //put this new node in the correct place in the tree
    tree->root=new_node;
    tree->elementCount+=1;
    return 0;   
}

void printtabs(int numtabs){
    for (int i=0;i<numtabs;i++){
        printf("\t");
    }
}

void printtree_rec(Tree *root, int level){
    if(root==NULL){
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    printf("value = %d\n", root->value);
    printtabs(level);
    printf("left\n");

    printtree_rec(root->left,level+1);
    printtabs(level);
    printf("right\n");

    printtree_rec(root->right,level+1);

    printtabs(level);
    printf("done\n");
}


int main(){
    treenode *n1=createnode(11);
    treenode *n2=createnode(12);
    treenode *n3=createnode(13);
    treenode *n4=createnode(14);
    treenode *n5=createnode(15);

    n1->left=n2;
    n1->right=n3;

    n2->left=n4;
    n2->right=n5;

    printtree_rec(n1,0);


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

}