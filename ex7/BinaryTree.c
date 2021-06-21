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

int insertNodeByOrder(Tree* tree,Node* toInsert,unsigned int (*toInsert_IsLarger)(Node*,Node*)){
    Node* current=tree->root;
    while(current != NULL){
        if(toInsert_IsLarger(current,toInsert)==1){
            if(current->right ==NULL){
                current->right=toInsert;
                break;
            }else{
                current = current->right;
            }
        }else{
            if(current->left ==NULL){
                current->left=toInsert;
                break;
            }else{
                current = current->left;
            }
        }
    }
    return 0;
}

int addNewNode(Tree* tree,void (*create_obj)(Node*),unsigned int (*compare)(Node*,Node*)){
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
        if(compare==NULL){
            insertNodeNoOrder(tree,new_node);
        }else{
            insertNodeByOrder(tree,new_node,compare);
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


 Node* minValueNode(Node* node)
{
    Node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    return current;
}

int insertTree(Tree *main, Node *toInsert,unsigned int (*compare)(Node*,Node*)){
    if(toInsert!=NULL){
        insertNodeByOrder(main,toInsert,compare);
        insertTree(main, toInsert->left,compare);
        insertTree(main, toInsert->right,compare);
        return 0;
    }
    return -1;
}

int removeNode(Tree* tree, Node* parent, Node* toRemove,unsigned int (*compare)(Node*,Node*)){
    //go left or right by the client id until you find the node
    if(parent==NULL || toRemove==NULL){
        return -1;
    }else if(compare(parent,toRemove)==0){
        Node* smallTreeRoot=toRemove->left;
        tree->root=toRemove->right;
        free(toRemove->value);
        free(toRemove);
        insertTree(tree,smallTreeRoot,compare);
        return 0;
    }else if(compare(parent->left,toRemove)==0){
        Node* smallTreeRoot=toRemove->left;
        parent->left=toRemove->right;
        free(toRemove->value);
        free(toRemove);
        insertTree(tree,smallTreeRoot,compare);
        return 0;
    }else if(compare(parent->right,toRemove)==0){
        Node* smallTreeRoot=toRemove->left;
        parent->right=toRemove->right;
        free(toRemove->value);
        free(toRemove);
        insertTree(tree,smallTreeRoot,compare);
        return 0;
    }
    else if(compare(parent->right,toRemove)==1){//toRemove>parent->right
        removeNode(tree,parent->right,toRemove,compare);
    }else{
        removeNode(tree,parent->left,toRemove,compare);        
    }
    return -1;

}

