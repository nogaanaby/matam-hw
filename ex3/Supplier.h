
#ifndef SUPPLIER_H
#define SUPPLIER_H

#define TEN 10
#define FIVE 5
#include "Utils.h"
typedef struct Supplier {
  char *id;
  char *name;
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
//int addNewSupplier(Suppliers_List* sup_list);
//int get_supplier_input_from_user(Supplier *temp_sup);
//Supplier* searchBy_Supplier_id( Supplier* sup_list, int supplier_id);
//Supplier* searchBy_Supplier_name( Supplier* sup_list,char* value);
//void threeGreatestSupplier_REC(Suppliers_List *Suppliers_list,int* licenses_arr);
//void ShallowCopySuppliersList(Suppliers_List *to, Suppliers_List *from);
//int popSmallestTransactionsSupplier(Suppliers_List *sl);
void print_sup_list(Supplier_Node* head);
void print_sup(Supplier* sup);
//int deleteSupplier(Suppliers_List* sup_list,int Supplier_id);
//int deleteAllSuppliers(Suppliers_List* sup_list);

int addNewSupplier_test(Suppliers_List* sup_list,char *id,char *name,int phone_number, 
  int count_transactions, int sum_of_total_transactions_price);

#endif

