/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> 


typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
} Node;

/*func declarioton*/
Node *create_root();
void insert_to_tree(Node *head);
Node *insert_to_tree_rec(Node *head,Node *new_node);
int isOrderTree(Node *head);
void print_tree(Node* root);
Node* findMaxInOrderTree(Node *head);
int symmetricCount(Node *head,int *high);



int main()
{   
    Node *tree  = (Node*)malloc(sizeof(Node));
    tree = create_root();
    for(int i =0 ; i < 10 ; i++){
        insert_to_tree(tree);
    }
    printf((isOrderTree(tree)) ? "\nbinary tree is not order\n" : "\n binary tree is order\n");
    Node* res = findMaxInOrderTree(tree);
    print_tree(tree);
    printf("max key = %d \n",res->key);
    printf("res is : %d\n",symmetricCount(tree,0));
    return 0;
}

/*return the number of all symmertic sub tree in T */
/*add only tow parms*/
/*evrey tree will count as sub tree and evrey leaf is a sub symmetric tree */
int symmetricCount(Node *head ,int *high){
    if(!head->left && !head->right){
        return 1;
        *high++;
    }
    else if(!head->left && head->right){
        *high++;
        return symmetricCount(head->right,high);
    }else if(head->left && !head->right){
        *high++;
        return symmetricCount(head->left,high);
    }else{
        *high++;
        return 1 + symmetricCount(head->left,high) + symmetricCount(head->right,high) ; 
    }
    
}


/*return node  with max value  in tree */
Node* findMaxInOrderTree(Node *head){
    if(!head->right){
        return head; 
    }
    findMaxInOrderTree(head->right);
}

int isOrderTree(Node *head){
    if(head->right && head->left){
        return 1;
    }else if(!head->left && head->right || head->left && !head->right){
        return 0 ;
    }else if(head->key < head->left->key && head->key < head->right->key && head->left->key < head->right->key ){
        return 1 && isOrderTree(head->right) && isOrderTree(head->left); 
    }   
}

Node *create_root(){
   /* int arr[3] = {10,11,100};*/
    int static i = 0 ;
    Node *root = (Node*)malloc(sizeof(Node));
    if(root){
    /*    root->key = arr[i] ; 
    */  root->key = rand()%50+i ; 
        printf("key = %d \t",root->key);
        root->left = NULL ; 
        root->right = NULL;
        i++;
        return root ;
    }
}

void insert_to_tree(Node *head){
    if(head){
        Node* temp = create_root();
        head = insert_to_tree_rec(head,temp);
    }
}

/*insert  node  to  tree */
Node* insert_to_tree_rec(Node *head,Node * new_node){
    if(head == NULL ){
        return new_node; 
    }    
    if(head->key > new_node->key){
        head->left = insert_to_tree_rec(head->left,new_node);
    }else if(head->key < new_node->key){
        head->right = insert_to_tree_rec(head->right,new_node);
    }
    return head;
}

void print_tree(Node *root){
    if(root == NULL ){
        return ; 
    }
    print_tree(root->left);
    printf("[root -> key  : %d  ]\n\n",root->key);
    print_tree(root->right);
    
}
