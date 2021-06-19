#include "BinaryTree.h"

Tree *createTree(){
    Tree* result = malloc(sizeof(Tree));
    if(result!=NULL){
        result->root = NULL;
        result->elementCount= 0;
    }
    return result;
}



int insertNodeNoOrder(Tree* tree,Node* toInsert){
    Node* current=tree->root;
    if(current->left==NULL){
        current->left=toInsert;
        return 0;
    }else if(current->right==NULL){
        current->right=toInsert;
        return 0;
    } else{
        current=current->left;
    }

}

int insertNodeByOrder(Tree* tree,Node* toInsert,bool (*toInsert_IsLarger)(Node*,Node*)){
    Node* current=tree->root;
    while(current != NULL){
        if(toInsert_IsLarger(current,toInsert)){
            if(current->left ==NULL){
                current->left=toInsert;
                break;
            }else{
                current = current->left;
            }
        }else{
            if(current->right ==NULL){
                current->right=toInsert;
                break;
            }else{
                current = current->right;
            }
        }
    }
    return 0;
}

int addNewNode(Tree* tree,void (*create_obj)(Node*),bool (*orderBy)(Node*,Node*)){
    Node* new_node= (Node*) malloc(sizeof(Node));
    create_obj(new_node);
    new_node->left=NULL;
    new_node->right=NULL;
    
    if(tree->root==NULL){
        tree->root=(Node*) malloc(sizeof(Node));
        tree->root=new_node;
        return 0;
    }else{
        //put this new node in the correct place in the tree
        if(orderBy==NULL){
            insertNodeNoOrder(tree,new_node);
        }else{
            insertNodeByOrder(tree,new_node,orderBy);
        }
        tree->elementCount+=1;
        return 0;
    }
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


