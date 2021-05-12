#include "Utils.h"
#include "Supplier.h"


int createSuppliersList(struct Supplier* sup_list){
    int i = 0 ;
    get_int_input("please enter size of array",&size_k,TEN);
    while(size_k < 1 && size_k >  K ){
        printf("error k suold be grether then 1 or biger  then 50 \n");
        get_int_input("please enter size of array",&size_k,TEN);
    }
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
 int addNewSupplier(struct Supplier* sup_list,struct Supplier *push_here){
     struct Supplier temp_sup;
     if(get_input_from_user_sup(&temp_sup))
     addSupToArray(&temp_sup,sup_list);
    /*when supplier  is created updatse the three bigest suppliers */
     add_to_bigest_sup_sum(&temp_sup,push_here);
     count_index++;
     return 0;   
 }

int add_to_bigest_sup_sum(struct Supplier *s,struct Supplier *push_here){
    if(count_index < 3  && s && push_here){
        (push_here+count_index)->count_transactions = s->count_transactions;
        (push_here+count_index)->id = s->id;
        strcpy((push_here+count_index)->name,s->name);
        (push_here+count_index)->phone_number = s->phone_number;
        (push_here+count_index)->sum_of_total_transactions_price = s->sum_of_total_transactions_price;
        (push_here+count_index)->is_empty = 0 ;
        printf("count->index =  %d \n",count_index); 
        return 0 ;
    }else if( s && push_here){
        int i = 0 ; 
        for(i = 0 ; i < FIVE-2 ; i++){
            printf("count->index =  %d \n",count_index);
            if((push_here+i)->sum_of_total_transactions_price < s->sum_of_total_transactions_price){
                (push_here+i)->count_transactions = s->count_transactions;
                (push_here+i)->id = s->id;
                strcpy((push_here+i)->name,s->name);
                (push_here+i)->phone_number = s->phone_number;
                (push_here+i)->sum_of_total_transactions_price = s->sum_of_total_transactions_price;
                (push_here+i)->is_empty = 0 ; 
                return 0 ; 
            }
        }
    }
    return -1; 

}

int get_input_from_user_sup(struct Supplier *temp_sup){
    if(temp_sup){
        get_int_input("Please enter (10 digit) sup id number:\t",&temp_sup->id,TEN);
        get_int_input("Please enter (10 digit) supplier sum of transactions:\t",&temp_sup->sum_of_total_transactions_price,TEN);
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
        int i = 0; 
        if(sup_list){
            for(; i < FIVE -2 ; i++){
                print_sup(sup_list+i);
            }
        }
}

int add_to_supplier_sum_of_transactions(struct Supplier* sup_list,int amount,char* name){
    struct Supplier *s =  searchBy_Supplier_name(sup_list,name);
    if(s){
        (s)->sum_of_total_transactions_price += amount;
        printf("add %d to sum of  transactions of supplier : %s ",amount,s->name);
    }
    return -1;
}

// sarch for Supplier in data base 
 struct Supplier* searchBy_Supplier_id( struct Supplier* sup_list,int Supplier_id){
     int i = 0 ; 
     if(sup_list){
         for(i = 0 ; i < size_k ; i++){
            if(!(sup_list+i)->is_empty && (sup_list+i)->id == Supplier_id ){
                return (sup_list+i); 
            }
         }
     }
     return NULL; 
 }

struct Supplier* searchBy_Supplier_name( struct Supplier* sup_list,char* value){
    int i = 0 ;
    if(sup_list){
        for(i =0 ; i < size_k ; i++){
            if(!(sup_list+i)->is_empty && strcmp((sup_list+i)->name,value) == 0 ){
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
        (s)->id = 0;
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

