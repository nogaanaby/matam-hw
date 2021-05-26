
#ifndef SUPPLIER_H
#define SUPPLIER_H

#define TEN 10
#define FIVE 5
#define K 50

typedef struct Supplier {
  int id;
  /* alloceted  fields  */
  char *name;
  /* alloceted  fields  */
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

/* create array of Suppliers with stdin input K */
Suppliers_List* createSuppliersList();
/* add new supplier function */ 
int addNewSupplier(Suppliers_List* sup_list);
int get_supplier_input_from_user(Supplier *temp_sup);
/* search function */
//Supplier* searchBy_Supplier_id( Supplier* sup_list, int supplier_id);
//Supplier* searchBy_Supplier_name( Supplier* sup_list,char* value);
void threeGreatestSuppliers(Suppliers_List* sup_list);
/*when supplier  is created updatse the three bigest suppliers */
//int add_to_bigest_sup_sum(struct Supplier *s,struct Supplier *push_here);
/* update supplier sum of transaction */
//int add_to_supplier_sum_of_transactions(struct Supplier* sup_list,int amount,char* name);
/* print function */
void print_sup_list(Supplier_Node* head);
void print_sup(Supplier* sup);
/* delete function */
int deleteSupplier(Suppliers_List* sup_list,int Supplier_id);
int deleteAllSuppliers(Suppliers_List* sup_list);

int addNewSupplier_test(Suppliers_List* sup_list,int id,char *name,int phone_number, 
  int count_transactions, int sum_of_total_transactions_price, int is_empty);

#endif

