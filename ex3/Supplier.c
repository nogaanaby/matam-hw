#include "Utils.h"
#include "Supplier.h"
 int size_k = 0 ;
 int count_index = 0 ;

Suppliers_List* createSuppliersList(){
    Suppliers_List *new_list = (Suppliers_List*) malloc(sizeof(Suppliers_List));
    if(new_list == NULL ){
        printf("error list is empty\n");
    }else{
        new_list->head = NULL; 
        new_list->size_count = 0 ; 
        return new_list;
    }
}
/* add a new Supplier to array of Supplier = > 1.check for this Supplier in data 2.find the pleace in array 
 3. return error if in array */ 
 int addNewSupplier(Suppliers_List* sup_list){
    Supplier_Node* new_supplier_node = (Supplier_Node *) malloc(sizeof(Supplier_Node));
    Supplier* new_supplier = (Supplier *) malloc(sizeof(Supplier));

    get_supplier_input_from_user(new_supplier);
    new_supplier_node->supplier = new_supplier;
    new_supplier_node->next = sup_list->head;
    sup_list->head = new_supplier_node;
    sup_list->size_count+=1;
    return 0; 
 }


int get_supplier_input_from_user(struct Supplier *temp_sup){
    if(temp_sup){
        get_chr_input("Please enter (10 digit) sup id number:\t",temp_sup->id,TEN);
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
#ifdef DAVIS 
void print_sup_list(Supplier_Node* head){
    Supplier_Node *current = head;

    while (current != NULL) {
        print_sup(current->supplier);
        current = current->next;
    }   
}
#endif

void threeGreatestSupplier_REC(Suppliers_List *Suppliers_list, char* licenses_arr){
    if (Suppliers_list->size_count<=3){
        int i=0;
        Supplier_Node *current = Suppliers_list->head;
        while (current != NULL) {
            strcat(licenses_arr,current->supplier->id);
            strcat(licenses_arr,", ");
            current = current->next;
            i++;
        }
        strcat(licenses_arr,"\0");
    }else{
        Suppliers_List *poped_list=createSuppliersList();
        Supplier_Node* poped_list_head = copyList(Suppliers_list->head);
        poped_list->size_count=Suppliers_list->size_count;
        poped_list->head=poped_list_head;
        popSmallestTransactionsSupplier(poped_list);
        threeGreatestSupplier_REC(poped_list, licenses_arr);
        free(poped_list);
    }
}

struct Supplier_Node* copyList(struct Supplier_Node* head)
{
    if (head == NULL) {
        return NULL;
    }
    else {
        struct Supplier_Node* newNode
            = (struct Supplier_Node*)malloc(
                sizeof(struct Supplier_Node));
  
        newNode->supplier = head->supplier;
        newNode->next = copyList(head->next);
        return newNode;
    }
}

int popSmallestTransactionsSupplier(Suppliers_List *sl){
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
}

/* delete all Supplier */ 
int deleteAllSuppliers(Suppliers_List *Suppliers_list){
    int i = 0;
    if(Suppliers_list == NULL ){
        printf("list is empty\n");
        return -1;
    }
    while(Suppliers_list->head!= NULL){
        deleteSupplier(Suppliers_list,Suppliers_list->head->supplier->id);
    } 
    return 0 ; 
}

int deleteSupplier(Suppliers_List* Suppliers_list, char *id) {
    int i = 0;
    Supplier_Node * current = Suppliers_list->head;
    Supplier_Node * Supplier_node_to_delete = NULL;

    /*no Suppliers on the list*/
    if(current==NULL){
        return -1;
    }
    /*if its the head of the list*/
    if(strcmp(current->supplier->id,id)==0){
        if(current->next!=NULL){
            Suppliers_list->head=current->next;
        }else{
            Suppliers_list->head=NULL;
        }
        free(current->supplier);
        free(current);
        Suppliers_list->size_count-=1;
        return 0;
    }

    for (i = 0; i < Suppliers_list->size_count; i++) {
        if(current->next){
            if(strcmp(current->next->supplier->id,id)==0){
                Supplier_node_to_delete = current->next;
                /*if its not the end of the list I want that the prev node will point the next node: prev->Supplier_to_delete->next*/
                if (current->next->next) {
                    current->next=current->next->next;
                }else{/*it is the end of the list*/
                    current->next=NULL;
                }
                free(Supplier_node_to_delete);
                Suppliers_list->size_count-=1;
                return 0;
            }
        }
        current = current->next;
    }
    /*if the id wasnt in the list*/
    return -1;
}


int addNewSupplier_test(Suppliers_List* sup_list,char *id,char *name,int phone_number, 
  int count_transactions, int sum_of_total_transactions_price){
        Supplier_Node* snode1=(Supplier_Node *) malloc(sizeof(Supplier_Node));
        Supplier *new_supplier=(Supplier *) malloc(sizeof(Supplier));

        strcpy(new_supplier->id, id);
        strcpy(new_supplier->name, name);
        new_supplier->phone_number=phone_number;
        new_supplier->count_transactions=count_transactions;
        new_supplier->sum_of_total_transactions_price=sum_of_total_transactions_price;
        new_supplier->is_empty=0;

        snode1->supplier=new_supplier;
        snode1->next=sup_list->head;
        sup_list->head = snode1;
        sup_list->size_count+=1;

        return 0; 
}