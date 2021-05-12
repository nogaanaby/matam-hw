//declare functions, 
//global variables use outside the class declare, 
//and types

#ifndef SUPPLIER_H
#define SUPPLIER_H


#define TEN 10
#define FIVE 5
#define K 50 

static unsigned int size_k = 0 ;
static unsigned int count_index = 0 ; 

struct Supplier {
  int id;
  char name[FIVE];
  int phone_number;
  int count_transactions;
  int sum_of_total_transactions_price;
  int is_empty;
};

/* create array of Suppliers with stdin input K */
int createSuppliersList(struct Supplier* sup_list);
/* add new supplier function */ 
int addNewSupplier(struct Supplier *temp_sup);
int addSupToArray(struct Supplier *temp_sup,struct Supplier* sup_list);
int get_input_from_user_sup(struct Supplier *temp_sup);
/* search function */
struct Supplier* searchBy_Supplier_id( struct Supplier* sup_list, int supplier_id);
struct Supplier* searchBy_Supplier_name( struct Supplier* sup_list,char* value);
struct Supplier* threeGreatestSuppliers(struct Supplier* sup_list);
/* update supplier sum of transaction */
int add_to_supplier_sum_of_transactions(struct Supplier* sup_list,int amount,char* name);
/* print function */
void print_sup_list(struct Supplier* sup_list);
void print_sup(struct Supplier* sup);
/* delete function */
int deleteSupplier(struct Supplier* sup_list,int Supplier_id);
void deletSingleSupplier(struct Supplier *s); 
int deleteAllSuppliers(struct Supplier *sup_list);

#endif

