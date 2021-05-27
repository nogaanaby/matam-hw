#include "Linked_List_car.h"



List* CreateCarList(){   
    List *new_list = (List*) malloc(sizeof(List));
    if(new_list){
        new_list->head = NULL; 
        new_list->size_count = 0 ; 
        return new_list;
    }
    /* allocetion field exit prog */
    printError(NULL_);
    return NULL;
}

/* remove from file only test */
 void get_car_test(struct Car* car){
    static int i  = 1 ; 
    car->frame_id = (12345+i) ; 
    car->license_id = (1234567+i) ;
    if(i==1 || i == 3){car->year_of_relase = 2012-(i*10);}
    else{car->year_of_relase = 2012+i;} 
    car->manufacturer_name = my_strdup("nisan") ; 
    car->model_name = my_strdup("micra") ; 
    car->color = my_strdup("red");
    car->road_raising_year = 1992+i ; 
    car->supplier_price = 20000000+i; 
    car->current_price =  20000000+i;
    car->engine_capacity = 2000+i;
    i++;
}
/* remove from file only test */

void addCarToList(Node** head){
     Node* new_node_car = (Node*) malloc(sizeof(Node));
     new_node_car->car = ( Car*) malloc(sizeof( Car));
     get_car_test(new_node_car->car);
     if(new_node_car){
/*          get_input_from_user(new_node_car->car); */         
            addCarToLinkedList(head,new_node_car);
            sort_by_year_of_relase(*head);
     }
}

int addCarToLinkedList(struct Node **head,struct Node* car_node){
            if(car_node){
                car_node->next = *head;
                *head  = car_node;
                return 0 ; 
            }
        return -1;
}
/* function will sort the array */
void sort_by_year_of_relase(struct Node *head){
    struct Node *temp = head;
    struct Node *pnode = head; 
    while(pnode != NULL)
    {
        temp=head; 
        while (temp->next !=NULL)
        {
           if(temp->car->year_of_relase > temp->next->car->year_of_relase)
            {
              repalce(temp,temp->next);
            }
         temp = temp->next;   
        }
        pnode = pnode->next;   
    }
}

/* swap between tow cars  */
void repalce( Node *target, Node* source ){
    struct Car *temp = target->car; 
    target->car = source->car;
    source->car = temp;
}

void get_input_from_user(struct Car* temp_car){
    get_int_input("Please enter (7 digit) license id number:\t",&temp_car->license_id,MAX_LEN_SEVEN);
    get_int_input("Please enter (5 digit) frame id number:\t",&temp_car->frame_id,MAX_LEN_FIVE);
    get_int_input("Please enter (4 digit) year of relase:\t",&temp_car->year_of_relase,MAX_LEN_FOUR);
    get_chr_input("Please enter (10 digit) manufacturer name:\t",temp_car->manufacturer_name,ALLOC);
    get_chr_input("Please enter (10 digit) model name:\t",temp_car->model_name,ALLOC);
    get_chr_input("Please enter (7 digit) color of car:\t",temp_car->color,ALLOC);
    get_int_input("Please enter (4 digit) road raising year:\t",&temp_car-> road_raising_year,MAX_LEN_FOUR);
    get_int_input("Please enter (7 digit) supplier price:\t",&temp_car-> supplier_price,MAX_LEN_SEVEN);
    get_int_input("Please enter (7 digit) current price:\t",&temp_car-> current_price,MAX_LEN_SEVEN);
    get_int_input("Please enter (4 digit) engine_capacity:\t",&temp_car-> engine_capacity,MAX_LEN_FOUR);
}

struct Car* FindCarInListById(Node* head,Node* prev,int id){
    struct Node *temp = head; 
    if(!temp){return NULL ; }
    while(temp){
        if(temp->car->license_id == id){
            return temp->car; 
        }
        prev = temp; 
        temp = temp->next;  
    }
    /* car is not found */
    prev = NULL;
    return NULL;
}

void printCarList(Node* head){
    struct Node *temp = head;
    int i = 0 ; 
    if(!temp){ printf("error list is empty\n"); return;}
    while(temp){
        printf("car in index number %d ->\n",i);     
        print_car(temp->car); 
        temp = temp->next; 
        i++;
        printf("\n");
    }
    
}



/* free all alloceted field */
void free_car(Node* tmp){
        free(tmp->car->manufacturer_name);
        free(tmp->car->model_name);
        free(tmp->car->color);
        free(tmp);
}

int removeCarFromList(Node* head,int id){
    Node *tmp = NULL ;
    Node *prev = NULL; 
    if(!head){return -1;}
    if(FindCarInListById(head,prev,id)){
        if(tmp){
            /* on top of the list */
            if(!tmp->next){
            free_car(tmp);
            return 0 ; 
            }
            /* if  gat a prev */
            if(prev){
                prev->next = tmp->next ; 
                free_car(tmp); 
                return 0 ;
            }
        }
    }
    printf("error item id : %d not found in list !\n",id);
    return -1;
}

void print_car(struct Car* car){
                if(car){
                    printf("color:\t%s\n",(car)->color);
                    printf("price:\t%d\n",(car)->current_price);
                    printf("engine capcity\t%d\n",(car)->engine_capacity);
                    printf("freme number:\t%d\n",(car)->frame_id);
                    printf("license number:\t%d\n",(car)->license_id);
                    printf("manufacturer name:\t%s\n",(car)->manufacturer_name);
                    printf("model name:\t%s\n",(car)->model_name);
                    printf("road rising year :\t%d\n",(car)->road_raising_year);
                    printf("supplier_price:\t%d\n",(car)->supplier_price);
                    printf("year of relase:\t%d\n\n",(car)->year_of_relase);
                }
                
}

void destroyCarList(Node** head){
    Node *del_node ;
    Node *temp = *head;  
    while(temp){
        del_node = temp ;
        temp = temp->next;  
        free_car(del_node); 
    }
    *head = NULL ; 
}


