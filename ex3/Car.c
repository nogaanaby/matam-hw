
#include "car.h"
#include "Utils.h"
 int count_index_array = 0 ;


/* create array of cars fix size N, set the fildes to zero */ 
int createCarTree(struct Car* car){
        int i=0;
        if(car == NULL ){printf("error list is empty\n");return -1;}
        for( ; i <  N ; i++){
            strcpy((car+i)->color,"");
            (car+i)->current_price =0;
            (car+i)->engine_capacity =0;
            (car+i)->frame_id = 0;
            (car+i)->license_id = 0;
            strcpy((car+i)->manufacturer_name,"");
            strcpy((car+i)->model_name,"");
            (car+i)->road_raising_year = 0;
            (car+i)->supplier_price = 0;
            (car+i)->year_of_relase = 0;
            (car+i)->is_empty = 1 ;             
        }
    return 0;
}

 
/* chenge is_empty to false*/
/*splite into 3 function 1. get_input 2. check input 3. 
return car and put into array in index  */
  
int  addNewCar(struct Car *car_list,struct Supplier *s){ 
    Car temp_car ;
    get_input_from_user(&temp_car,s);
    addCarToArray(&temp_car,car_list);
    return 0 ;
}

int get_input_from_user(struct Car *temp_car,struct Supplier *s){
    get_int_input("Please enter (7 digit) license id number:\t",&temp_car->license_id,MAX_LEN_SEVEN);
    get_int_input("Please enter (5 digit) frame id number:\t",&temp_car->frame_id,MAX_LEN_FIVE);
    get_chr_input("Please enter (10 digit) manufacturer name:\t",temp_car->manufacturer_name,MAX_LEN_TEN);
    get_chr_input("Please enter (10 digit) model name:\t",temp_car->model_name,MAX_LEN_TEN);
    get_chr_input("Please enter (7 digit) color of car:\t",temp_car->color,MAX_LEN_SEVEN);
    get_int_input("Please enter (4 digit) year of relase:\t",&temp_car->year_of_relase,MAX_LEN_FOUR);
    get_int_input("Please enter (4 digit) road raising year:\t",&temp_car->road_raising_year,MAX_LEN_FOUR);
    get_int_input("Please enter (7 digit) supplier price:\t",&temp_car->supplier_price,MAX_LEN_SEVEN);
    get_int_input("Please enter (7 digit) current price:\t",&temp_car->current_price,MAX_LEN_SEVEN);
    get_int_input("Please enter (4 digit) engine_capacity:\t",&temp_car->engine_capacity,MAX_LEN_FOUR);
    /*update sum of transactions in supplier list */
    add_to_supplier_sum_of_transactions(s,temp_car->supplier_price,temp_car->manufacturer_name);
    printf("\n");
    (temp_car)->is_empty = 0 ;
    return 0; 
}
    
int  copy_car(struct Car *to,struct Car *from){
    if(from && to){
            strcpy((to)->color,from->color);
            (to)->current_price =from->current_price;
            (to)->engine_capacity =from->engine_capacity;
            (to)->frame_id = from->frame_id;
            (to)->license_id = from->license_id;
            strcpy((to)->manufacturer_name,from->manufacturer_name);
            strcpy((to)->model_name,from->model_name);
            (to)->road_raising_year = from->road_raising_year;
            (to)->supplier_price = from->supplier_price;
            (to)->year_of_relase = from->year_of_relase;
            (to)->is_empty = 0 ;
            return 1 ;                      
    }
    return 0 ;
} 


int addCarToTree(struct Car *car,struct Car *car_list){
    if(car && car_list && (car_list+count_index_array)->is_empty){
        if(copy_car(car_list+count_index_array,car)){
            printf("add new  car to array in index %d \n",count_index_array);
            count_index_array++;
            return 0; 
        }
    }
    return -1; 
}

/* sarch for cars in data base, return pointer from struct */ 
struct Car* searchBy_license_id( struct Car* car,int value){
int i = 0;
if(car == NULL ){printf("error list is empty\n");return NULL;}
    for( ; i < N ; i++){
        if((!(car+i)->is_empty) == 1){ 
            if((car+i)->license_id == value ){
                    printf("***find car in index %d***\n",i);
                    return (car+i);
            }
        }
    }
    return NULL;
}

int carNumberWithGivenCapacity( struct Car* car, int value){
    int count = 0 ; 
    int i =0;
    if(car == NULL ){printf("error list is empty\n");return 0;}
        for( ; i < N ; i++){
            if(!((car+i)->is_empty)){
                if( (car+i)->engine_capacity == value ){
                    count++;
                }
            }
    }
    return count;
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

void print_car_Tree(struct Car* car){
    int i = 0;
    for( ; i <  N ; i++){
        printf("index :\t%d\n",i);
        print_car(car+i);
    }     
}

/* delte car by id number*/
int deleteCar(struct Car* car,int license_id){
    struct Car* res = searchBy_license_id(car,license_id);
    if(res != NULL ){
        deleteSingleCar(res);
        return 0 ;
    }
    return -1 ; 
}

/* delete all cars */
int deleteAllCars(struct Car* car){
    int i = 0;
    if(car == NULL ){printf("list is empty\n");return -1;}
    for( ; i < count_index_array ; i++){
        deleteSingleCar(car+i); 
    } 
    count_index_array = 0 ; 
    return 0 ; 
}

void deleteSingleCar(struct Car* car){
        strcpy((car)->color,"");
        (car)->current_price = 0;
        (car)->engine_capacity = 0;
        (car)->frame_id = 0 ; 
        (car)->license_id = 0 ; 
        strcpy((car)->manufacturer_name,"");
        strcpy((car)->model_name,"");
        (car)->road_raising_year = 0;
        (car)->supplier_price = 0;
        (car)->year_of_relase = 0;
        (car)->is_empty = 1;
} 