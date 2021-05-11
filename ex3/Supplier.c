#include "Utils.h"
#include "Supplier.h"


int createSuppliersList(struct Supplier* sup_list){
    int i = 0 ;
    get_int_input("please enter size of array",&size_k,TEN);
    if( size_k < K && sup_list){
        for(i = 0 ; i < size_k ; i++){
            (sup_list+i)->id = 0 ; 
            (sup_list+i)->sum_of_total_transactions_price = 0 ;
            (sup_list+i)->count_transactions = 0; 
            (sup_list+i)->phone_number = 0 ; 
            strcpy((sup_list+i)->name,""); 
            (sup_list+i)->is_empty = 1; 
        }
        return 0;
    }
    printf("Error the size you give is to big or (array = null) \n");
    return -1;
}

// add a new Supplier to array of Supplier = > 1.check for this Supplier in data 2.find the pleace in array 
// 3. return error if in array 
 int addNewSupplier(struct Supplier* sup_list){
     struct Supplier temp_sup;
     if(get_input_from_user_sup(&temp_sup))
     addSupToArray(&temp_sup,sup_list);
     return 0;   
 }

int get_input_from_user_sup(struct Supplier *temp_sup){
    if(temp_sup){
        get_int_input("Please enter (10 digit) sup id number:\t",&temp_sup->id,TEN);
        get_int_input("Please enter (10 digit) price amount of transaction:\t",&temp_sup->sum_of_total_transactions_price,TEN);
        get_int_input("Please enter (5 digit) amount of transaction:\t",&temp_sup->count_transactions,FIVE);
        get_int_input("Please enter (10 digit) sup phone number:\t",&temp_sup->phone_number,TEN);
        get_chr_input("Please enter (10 digit) sup name:\t",temp_sup->name,FIVE);
        temp_sup->is_empty = 0 ; 
        printf("\n");
        printf(" add new supplier \n");
        return 1 ; 
     }
     return 0; 
}


int addSupToArray(struct Supplier *temp_sup,struct Supplier* sup_list){
    if(temp_sup && sup_list && (sup_list+count_index)->is_empty && size_k < K){
        (sup_list+count_index)->id = temp_sup->id;
        (sup_list+count_index)->count_transactions = temp_sup->count_transactions;
        (sup_list+count_index)->sum_of_total_transactions_price = temp_sup->sum_of_total_transactions_price; 
        strcpy((sup_list+count_index)->name,temp_sup->name);
        (sup_list+count_index)->phone_number = temp_sup->phone_number;
        (sup_list+count_index)->is_empty = 0; 
        count_index++;
        return 0; 
    }
    return -1; 
}

void print_sup(struct Supplier* sup){
            if(sup->is_empty){
                printf("supplier is empty\n");
            }else {
                printf("Supplier name:\t%s\n",(sup)->name);
                printf("Supplier phone number:\t%d\n",(sup)->phone_number);
                printf("Supplier id :\t%d\n",(sup)->id);
                printf("supplier sum of transactions:\t%d\n",(sup)->sum_of_total_transactions_price);
                printf("number of transactions:\t%d\n\n",(sup)->count_transactions);
            }  
}

void print_sup_list(struct Supplier* sup_list){
    int i = 0;
    for(i = 0 ; i < size_k ; i++){
        printf("index :\t%d\n",i);
        print_sup(sup_list+i);
    }     
}

struct Supplier* threeGreatestSuppliers(struct Supplier* sup_list){
    
}

// sarch for Supplier in data base 
 struct Supplier* searchBy_Supplier_id( struct Supplier* sup_list,int value){
     int i = 0 ; 
     if(sup_list){
         for(i = 0 ; i < size_k ; i++){
            if(!sup_list->is_empty && (sup_list+i)->id == value ){
                return (sup_list+i); 
            }
         }
     }
     return NULL; 
 }

// delte Supplier by id number
int deleteSupplier(struct Supplier* sup_list,int Supplier_id){
     struct Supplier* s = searchBy_Supplier_id(sup_list,Supplier_id);
     if(s){
         deletSingleSupplier(s);
         printf("supplier deleted \n");
         return 0 ; 
     }
     return -1; 
}

void deletSingleSupplier(struct Supplier *s){
        (s)->id = 0 ; 
        (s)->sum_of_total_transactions_price = 0 ;
        (s)->count_transactions = 0; 
        (s)->phone_number = 0 ; 
        strcpy((s)->name,""); 
        (s)->is_empty = 1; 
}

// delete all Supplier 
int deleteAllSuppliers(struct Supplier *sup_list){
    int i = 0 ; 
    if(sup_list){
        for(i = 0 ; i < count_index ; i++){
            if(sup_list+i){ deletSingleSupplier(sup_list+i); }
        }
    }
    count_index = 0 ; 
    return 0 ; 
}

