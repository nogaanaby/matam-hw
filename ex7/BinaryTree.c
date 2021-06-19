#include "BinaryTree.h"

Tree *createTree(){
    Tree* result = malloc(sizeof(Tree));
    if(result!=NULL){
        result->root = NULL;
        result->elementCount= 0;
    }
    return result;
}



int insertNodeNoOrder(Node* current,Node* toInsert){
    if(current==NULL){
        current=toInsert;
        return 0;
    }else if(current->left==NULL){
        current->left=toInsert;
        return 0;
    }else if(current->right==NULL){
        current->right=toInsert;
        return 0;
    } else{
        insertNodeNoOrder(current->left,toInsert);
    }

}

int insertNodeByOrder(Node* current,Node* toInsert,bool (*toInsert_IsLarger)(Node*,Node*)){
    if(current==NULL){
        current=toInsert;
        return 0;
    }else if(toInsert_IsLarger(current,toInsert)){
        insertNodeByOrder(current->left,toInsert,toInsert_IsLarger);
    }else{
        insertNodeByOrder(current->right,toInsert,toInsert_IsLarger);
    }
}
int addNewNode(Tree* tree,void (*create_obj)(Node*),bool (*orderBy)(Node*,Node*)){
    Node* new_node= (Node*) malloc(sizeof(Node));
    Node* current=tree->root;
    create_obj(new_node);
    new_node->left=NULL;
    new_node->right=NULL;
    //put this new node in the correct place in the tree
    if(orderBy==NULL){
        insertNodeNoOrder(tree->root,new_node);
    }else{
        insertNodeByOrder(tree->root,new_node,orderBy);
    }
    tree->elementCount+=1;
    return 0;   

}
void printtabs(int numtabs){
    for (int i=0;i<numtabs;i++){
        printf("\t");
    }
}

void printtree_rec(Node *root, int level,void (*print_obj)(Node*,int)){
    if(root==NULL){
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    print_obj(root,level);
    printtabs(level);
    printf("left\n");

    printtree_rec(root->left,level+1,print_obj);
    printtabs(level);
    printf("right\n");

    printtree_rec(root->right,level+1,print_obj);

    printtabs(level);
    printf("done\n");
}


