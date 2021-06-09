
#ifndef SUPPLIER_H
#define SUPPLIER_H

#define TEN 10
#define FIVE 5

#include "Utils.h"
typedef struct Supplier {
  char id[TEN+1];
  char *name;
  char phone_number[TEN+1];
  int count_transactions;
  int sum_of_total_transactions_price;
  int is_empty;
}Supplier;

typedef struct Supplier_Node {
	Supplier *supplier;
		struct Supplier_Node* left;
	  struct Supplier_Node* right;
    int sum_of_sub_tree_left;
    int sum_of_sub_tree_right; 
} Supplier_Node;

typedef struct {
	Supplier_Node* root;
	int elementCount;
} Suppliers_Tree;

Suppliers_Tree* createSuppliersTree();
int addNewSupplier(Suppliers_Tree* sup_list);
Supplier_Node* insertsupToTree(Supplier_Node * root , Supplier_Node *new_node);
int get_supplier_input_from_user(Supplier *temp_sup);
int averageOfSupplierMoney(Suppliers_Tree *tree);
int averageOfSupplierMoney_REC(Supplier_Node *head); 
int popSmallestTransactionsSupplier(Suppliers_Tree *sl);
void print_sup_Tree(Supplier_Node* head);
void print_sup(Supplier* sup);
Supplier_Node *clone_node(Supplier_Node *node);
Supplier_Node* rec_clone(Supplier_Node* head);
Suppliers_Tree* tree_clone(Suppliers_Tree* tree);
int deleteAllSuppliers(Suppliers_Tree  *Suppliers_Tree);
void  deleteAllSuppliers_REC(Supplier_Node *head);
void free_Suppliers(Supplier_Node * sup);
Supplier_Node* FindSupInTreeByid(Supplier_Node * sup,char * sup_id);
#endif

