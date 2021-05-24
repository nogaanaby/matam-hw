
#ifndef SUPPLIER_H
#define SUPPLIER_H


#define TEN 10
#define FIVE 5
#define K 50 

 

struct Supplier {
  int id;
  /* alloceted  fields  */
  char *name;
  /* alloceted  fields  */
  int phone_number;
  int count_transactions;
  int sum_of_total_transactions_price;
  int is_empty;
};

/* create array of Suppliers with stdin input K */
int createSuppliersList(struct Supplier* sup_list);
/* add new supplier function */ 
int addNewSupplier(struct Supplier* sup_list,struct Supplier *push_here);
int addSupToArray(struct Supplier *temp_sup,struct Supplier* sup_list);
int get_input_from_user_sup(struct Supplier *temp_sup);
/* search function */
struct Supplier* searchBy_Supplier_id( struct Supplier* sup_list, int supplier_id);
struct Supplier* searchBy_Supplier_name( struct Supplier* sup_list,char* value);
void threeGreatestSuppliers(struct Supplier* sup_list);
/*when supplier  is created updatse the three bigest suppliers */
int add_to_bigest_sup_sum(struct Supplier *s,struct Supplier *push_here);
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

