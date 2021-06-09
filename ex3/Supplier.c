#include "Utils.h"
#include "Supplier.h"
 int size_k = 0 ;
 int count_index = 0 ;

Suppliers_Tree * createSuppliersList(){
    Suppliers_Tree  *new_Tree = (Suppliers_Tree *) malloc(sizeof(Suppliers_Tree ));
    if(new_Tree == NULL ){
        printf("error tree is empty\n");
        return NULL;
    }else{
        new_Tree->root = NULL; 
        new_Tree->elementCount = 0 ; 
        return new_Tree;
    }
}
/* add a new Supplier to array of Supplier = > 1.check for this Supplier in data 2.find the pleace in array 
 3. return error if in array */ 
 int addNewSupplier(Suppliers_Tree * sup_Tree){
    Supplier_Node* new_supplier_node = (Supplier_Node *) malloc(sizeof(Supplier_Node));
    Supplier* new_supplier = (Supplier *) malloc(sizeof(Supplier));
    if(new_supplier && new_supplier_node && sup_Tree){
        get_supplier_input_from_user(new_supplier);
        new_supplier_node->supplier = new_supplier;
        new_supplier_node->left = NULL;
        new_supplier_node->right = NULL;
        new_supplier_node->sum_of_sub_tree_left = 0 ; 
        new_supplier_node->sum_of_sub_tree_right = 0 ; 
        sup_Tree->root = insertNodeToTree(sup_Tree->root,new_supplier_node);
        return 0; 
    }
    
 }


Supplier_Node* insertNodeToTree(Supplier_Node * root , Supplier_Node *new_node){
    if (root == NULL)
    {
        return new_node;
    }
    /* go right */
    if (root->sum_of_sub_tree_left > root->sum_of_sub_tree_right)
    {
        root->right = insertNodeToTree(root->right, new_node);
        root->sum_of_sub_tree_right++;
    }
    else
    {
        /* go left */
        root->left = insertNodeToTree(root->left, new_node);
        root->sum_of_sub_tree_left++;
    }
    return root;
 }


int get_supplier_input_from_user(struct Supplier *temp_sup){
    if(temp_sup){
        get_chr_input("Please enter (10 digit) sup id number:\t",temp_sup->id,TEN);
        get_int_input("Please enter (10 digit) supplier sum of transactions:\t",&temp_sup->sum_of_total_transactions_price,TEN);
        get_int_input("Please enter (5 digit) amount of transaction:\t",&temp_sup->count_transactions,FIVE);
        get_int_input("Please enter (10 digit) sup phone number:\t",&temp_sup->phone_number,TEN);
        get_chr_input("Please enter (10 digit) sup name:\t",temp_sup->name,TEN);
        temp_sup->is_empty = 0 ; 
        printf("\n");
        printf(" add new supplier \n");
        return 1 ; 
     }
     return 0; 
}


void print_sup(struct Supplier* sup){
            if(sup->is_empty){
                printf("supplier is empty\n");
            }else {
                printf("Supplier name:\t%s\n",(sup)->name);
                printf("Supplier phone number:\t%d\n",(sup)->phone_number);
                printf("Supplier id :\t%s\n",(sup)->id);
                printf("supplier sum of transactions:\t%d\n",(sup)->sum_of_total_transactions_price);
                printf("number of transactions:\t%d\n\n",(sup)->count_transactions);
            }  
}

void print_sup_Tree(Supplier_Node* head){
    if(head == NULL){
        return ; 
    }
    print_sup(head->supplier);
    print_sup_list(head->left);
    print_sup_list(head->right);
}

/* void threeGreatestSupplier_REC(Suppliers_Tree  *Suppliers_Tree , char* licenses_arr){
    if (Suppliers_Tree ->size_count<=3){
        Supplier_Node *current = Suppliers_Tree ->head;
        while (current != NULL) {
            strcat(licenses_arr,current->supplier->id);
            strcat(licenses_arr,", ");
            current = current->next;
        }
        strcat(licenses_arr,"\0");
    }else{
        Suppliers_Tree  *poped_list=createSuppliersList();
        Supplier_Node* poped_list_head = copyList(Suppliers_Tree ->head);
        poped_list->size_count=Suppliers_Tree ->size_count;
        poped_list->head=poped_list_head;
        popSmallestTransactionsSupplier(poped_list);
        threeGreatestSupplier_REC(poped_list, licenses_arr);
        free(poped_list);
    }
}


int popSmallestTransactionsSupplier(Suppliers_Tree  *sl){
    int min=-1;
    char *sup_id;
    Supplier_Node *current = sl->head;

    while (current != NULL) {
        if(current->supplier->sum_of_total_transactions_price <min || min==-1){
            min=current->supplier->sum_of_total_transactions_price;
            sup_id=current->supplier->id;
        }
        current = current->next;
    } 

    return deleteSupplier(sl,sup_id);
} */

/* delete all Supplier */ 
int deleteAllSuppliers(Suppliers_Tree  *Suppliers_Tree,char* id){
    if(Suppliers_Tree  == NULL ){
        printf("list is empty\n");
        return -1;
    }
    if(Suppliers_Tree->root != NULL ){
        deleteAllSuppliers_REC(Suppliers_Tree->root);
        free(Suppliers_Tree);
    } 
    return 0 ; 
}

void  deleteAllSuppliers_REC(Supplier_Node *head){
    if (head == NULL)
    {
        return;
    }
    destroyTree_REC(head->left);
    destroyTree_REC(head->right);
    free_Suppliers(head);
}

void free_Suppliers(Supplier_Node * sup){

}
/* 
int deleteSupplier(Suppliers_Tree * Suppliers_Tree , char *id) {

}
 */
