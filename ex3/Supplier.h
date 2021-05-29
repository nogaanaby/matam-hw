
#ifndef SUPPLIER_H
#define SUPPLIER_H

#define TEN 10
#define FIVE 5

#include "Utils.h"
typedef struct Supplier {
  char id[TEN+1];
  char name[TEN+1];
  int phone_number;
  int count_transactions;
  int sum_of_total_transactions_price;
  int is_empty;
}Supplier;

typedef struct Supplier_Node {
	Supplier *supplier;
	struct Supplier_Node* next;
} Supplier_Node;

typedef struct {
	Supplier_Node* head;
	unsigned int size_count;
} Suppliers_List;

Suppliers_List* createSuppliersList();
int addNewSupplier(Suppliers_List* sup_list);
int get_supplier_input_from_user(Supplier *temp_sup);
void threeGreatestSupplier_REC(Suppliers_List *Suppliers_list,char* licenses_arr);
struct Supplier_Node* copyList(struct Supplier_Node* head);
int popSmallestTransactionsSupplier(Suppliers_List *sl);
void print_sup_list(Supplier_Node* head);
void print_sup(Supplier* sup);
int deleteSupplier(Suppliers_List* sup_list,char* Supplier_id);
int deleteAllSuppliers(Suppliers_List* sup_list);

int addNewSupplier_test(Suppliers_List* sup_list,char *id,char *name,int phone_number, 
  int count_transactions, int sum_of_total_transactions_price);

#endif

