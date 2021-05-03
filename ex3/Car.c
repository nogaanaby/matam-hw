
#include "car.h"

// create array of cars fix size N, set the fildes to zero 
int createCarList(struct Car* car){
// to Do
    //check if the(car has the correct types and size
        if(car == NULL ){printf("error list is empty\n");return -1;}
        for(int i = 0 ; i <  N ; i++){
            /* init the string with zero*/
            strcpy((car+i)->color,"");
            (car+i)->current_price =0;
            (car+i)->engine_capacity =0;
            strcpy((car+i)->frame_id,"");
            strcpy((car+i)->license_id,"");
            strcpy((car+i)->manufacturer_name,"");
            strcpy((car+i)->model_name,"");
            (car+i)->road_raising_year = 0;
            (car+i)->supplier_price = 0;
            (car+i)->year_of_relase = 0;
            (car+i)->is_empty = 1 ;             
        }
    return 0;
}

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
struct Car* addNewCar(char* license_id, char frame_id[], char manufacturer_name[],char model_name[],
char color[],int year_of_relase, int road_raising_year, 
int supplier_price, int current_price, int engine_capacity){
// to Do
    /* chenge is_empty to false*/
    /*splite into 3 function 1. get_input 2. check input 3. 
    return car and put into array in index  */
    struct Car* pointer_to_car_object; 
    return pointer_to_car_object;
}

// sarch for cars in data base 
struct Car* searchBy_license_id( struct Car* car, char* value){
// to Do
    if(car == NULL ){printf("error list is empty\n");return -1;}
    for(int i =0 ; i < N ; i++){
        if((car+i)->is_empty == 1){ return NULL;}
        if( strcmp((car+i)->license_id,value) == 0 ){
            return (car+i);
        }
    }
    return NULL;
}

void print_car(struct Car* car){
    for(int i = 0 ; i <  N ; i++){
            if(car->is_empty == 1 ){
                printf("car is empty\n");
            }else {
            /* init the string with zero*/
                printf("color : %s\n",(car+i)->color);
                printf("price : %d\n",(car+i)->current_price);
                printf("engine capcity  : %d\n",(car+i)->engine_capacity);
                printf("freme number : %s\n",(car+i)->frame_id);
                printf("license number : %s\n",(car+i)->license_id);
                printf("manufacturer name : %s\n",(car+i)->manufacturer_name);
                printf("model name : %s\n",(car+i)->model_name);
                printf("price : %d\n",(car+i)->road_raising_year);
                printf("supplier_price : %d\n",(car+i)->supplier_price);
                printf("year of relase : %d\n",(car+i)->year_of_relase);
            }
    }     
}

struct Car* searchBy_engine_capacity( struct Car* car, char* value){
    if(car == NULL ){printf("error list is empty\n");return -1;}
        for(int i =0 ; i < N ; i++){
            if((car+i)->is_empty == 1){return NULL;}
            if( (car+i)->engine_capacity == value ){
                return (car+i);
            }
    }
    return NULL;
}

// delte car cy id number
int deleteCar(char* license_id){
    // do we need to move all the valus of array backword  ?
}

// delete all cars 
int deleteAllCars(struct Car* car){
    if(car == NULL ){printf("list is empty\n");return -1;}
    for(int i = 0 ; i < N && (car+i) != NULL ; i++){
            strcpy((car+i)->color,"");
            (car+i)->current_price = 0;
            (car+i)->engine_capacity = 0;
            strcpy((car+i)->frame_id,"");
            strcpy((car+i)->license_id,"");
            strcpy((car+i)->manufacturer_name,"");
            strcpy((car+i)->model_name,"");
            (car+i)->road_raising_year = 0;
            (car+i)->supplier_price = 0;
            (car+i)->year_of_relase = 0;  
    }
    car = NULL ; 
    return 0 ; 
}