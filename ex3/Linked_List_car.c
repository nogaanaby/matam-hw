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
}

void addCarToList(Node** head){
     Node* new_node_car = (Node*) malloc(sizeof(Node));
     new_node_car->car = ( Car*) malloc(sizeof( Car));  
     if(new_node_car && new_node_car){
         get_input_from_user(new_node_car->car);
         addCarToLinkedList(head,new_node_car);
     }
}

int addCarToLinkedList(struct Node **head,struct Node* car_node){
    Node *temp_node = *head; 
    Node *prev_node ; 
        if(head && car_node){
                while(temp_node){
                /* action  */
                    if(temp_node->car->year_of_relase > car_node->car->year_of_relase){
                        prev_node->next = car_node; 
                        car_node->next = temp_node;
                        printf("add new car to linked_List\n");
                        return 0 ; 
                    }
                /* save the previos  tmp_node  */
                prev_node = temp_node;
                temp_node = temp_node->next;
                }
                /* if exit loop this is the beigest  val and need to go to end of list */
                prev_node->next = car_node;
                car_node->next = NULL ; 
            }else{/* if list is empty  */
                car_node = *head;
                *head =  car_node;
            }
            return -1; 
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
    temp_car->is_empty = 0 ;
}

struct Car* findCarInListById(Node* head,int id){
    while(head){
        if(head->car->frame_id == id){
            return head->car; 
        }
        head = head->next;  
    }
    /* car is not found */
    return NULL;
}

void printCarList(Node* head){
    int i = 0 ; 
    if(!head){ printf("error list is empty\n"); return;}
    while(head){
        printf("car in index number %d ->  \n",i);     
        print_car(head->car); 
        head = head->next; 
        printf("\n");
    }
}


Node* get_prev(Node* head,struct Car* car){
    Node* prev; 
    while(head && head->next){
        if(car->frame_id == head->car->frame_id){
            return prev;
        }
        prev = head;
        head = head->next; 
    }
    return NULL;

}

/* free all alloceted field */
void free_car(Node* tmp){
        free(tmp->car->manufacturer_name);
        free(tmp->car->model_name);
        free(tmp->car->color);
        free(tmp);
}

int removeCarFromList(Node** head,int id){
    Node *tmp ;
    Node *prev; 
    tmp->car =  FindCarInListById(head,id); 
    if(tmp){
        /* on top of the list */
        if(!tmp->next){
          free(tmp);
          return 0 ; 
        }
        prev = get_prev(*head,tmp->car);
        /* if  gat a prev */
        if(prev){
            prev->next = tmp->next ; 
            tmp->next = NULL;
            free(tmp); 
            return 0 ;
        }
        /* if not prev and not top of list is the only elemnt then delete */
        free(tmp);
    }
    printf("error item id : %d not found in list !\n",id);
    return -1;
}

void print_car(struct Car* car){
            if(car->is_empty){
                printf("car is empty\n");
            }else {
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
    Node *tmp_node = *head;
    Node *del_node ; 
    while(tmp_node){
        del_node = tmp_node ;
        tmp_node = tmp_node->next;  
        free(del_node); 
    }
}


