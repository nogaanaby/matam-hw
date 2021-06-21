
#ifndef SUPPLIER_H
#define SUPPLIER_H

#define TEN 10
#define FIVE 5
#include "BinaryTree.h"
#include "Utils.h"

typedef struct Supplier {
  char id[TEN+1];
  char *name;
  char phone_number[TEN+1];
  int count_transactions;
  int sum_of_total_transactions_price;
  int is_empty;
}Supplier;

Tree* createSuppliersTree();
int addNewSupplier(Tree* sup_list);
unsigned int compereSupplier(Node *node1,Node *node2);
void createSupplier(Node *new_node);
int get_supplier_input_from_user(Supplier *temp_sup);
void print_sup_Tree(Tree* tree);
void print_sup(Node *node,int count);
void DeleteAllSuppliers(Tree *tree);
void free_Suppliers(Node * sup);
Node* FindSupInTreeByid(Node * sup,char * sup_id);

/* int averageOfSupplierMoney(Tree *tree);
int averageOfSupplierMoneyier_Node(Node *head); 
int popSmallestTransactionsSupplier(Tree *sl);
 */

#endif

