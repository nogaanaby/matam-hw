
#include "car.h"
#include "Utils.h"

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
            (car+i)->is_empty = 0 ;             
        }
    return 0;
}

// add a new car to array of cars = > 1->check for this car in data 2->find the pleace in array 
// 3-> return error if in array 
int addNewCar(struct Car *car_list){
// to Do 
    struct Car to_car ;
    int res = get_input_from_user(&to_car);
    if(res != -1){
        print_car(&to_car);
        addCarToArray(&to_car,car_list);
        // add car to array function 
        printf("add new car to array\n");
    }else {
        printf("erorr invalid input, input is rejacted ! \n");
        return -1;
    }
    
    /* chenge is_empty to false*/
    /*splite into 3 function 1-> get_input 2-> check input 3-> 
    return car and put into array in index  */
    
}

int get_input_from_user(struct Car *to_car){
    int res = 0 ; 
    res = get_chr_input("Please enter (7 digit) license id number:\t",to_car->license_id,MAX_LEN_SEVEN);
    res = get_chr_input("Please enter (5 digit) frame id number:\t",to_car->frame_id,MAX_LEN_FIVE);
    res = get_chr_input("Please enter (10 digit) manufacturer name:\t",to_car->manufacturer_name,MAX_LEN_TEN);
    res = get_chr_input("Please enter (10 digit) model name:\t",to_car->model_name,MAX_LEN_TEN);
    res = get_chr_input("Please enter (7 digit) color of car:\t",to_car->color,MAX_LEN_SEVEN);
    res = get_int_input("Please enter (4 digit) year of relase:\t",&to_car->year_of_relase,MAX_LEN_FOUR);
    res = get_int_input("Please enter (4 digit) road raising year:\t",&to_car->road_raising_year,MAX_LEN_FOUR);
    res = get_int_input("Please enter (7 digit) supplier price:\t",&to_car->supplier_price,MAX_LEN_SEVEN);
    res = get_int_input("Please enter (7 digit) current price:\t",&to_car->current_price,MAX_LEN_SEVEN);
    res = get_int_input("Please enter (4 digit) engine_capacity:\t",&to_car->engine_capacity,MAX_LEN_FOUR);
    // res is overlodad  not god  need  to fix  //
    if(res == -1){
        printf("error input is invlid \n");
        (to_car)->is_empty = 1 ;
        return -1 ;
    }
    printf("\n");
    (to_car)->is_empty = 0 ;
    return 0; 
}
    
int  copy_car(struct Car *to,struct Car *from){ 
        if(to && from){
        strcpy(to->color,from->color);
        to->current_price = from->current_price;
        to->engine_capacity = from->engine_capacity;
        strcpy(to->frame_id,from->frame_id);
        strcpy(to->license_id,from->license_id);
        strcpy(to->manufacturer_name,from->manufacturer_name);
        strcpy(to->model_name,from->model_name);
        to->road_raising_year = from->road_raising_year;
        to->supplier_price = from->supplier_price;
        to->year_of_relase = from->year_of_relase;
        to->is_empty = 0 ;
        return 1;     
        }
        return -1; 
}


int addCarToArray(struct Car* car,struct Car* car_list){
    if(car_list && car ){
        if(copy_car((car_list+count_index_array),car)){
            count_index_array++;
            return 0 ; 
        }
    }
    return -1 ; 
}

// sarch for cars in data base 
struct Car* searchBy_license_id( struct Car* car, char* value){
// to Do
    if(car == NULL ){printf("error list is empty\n");return NULL;}
    for(int i = 0 ; i < N ; i++){
        if((car+i)->is_empty == 1){ return NULL;}
        if( strcmp((car+i)->license_id,value) == 0 ){
            return (car+i);
        }
    }
    return NULL;
}

struct Car* searchBy_engine_capacity( struct Car* car, char* value){
    if(car == NULL ){printf("error list is empty\n");return NULL;}
        for(int i =0 ; i < N ; i++){
            if(!((car+i)->is_empty)){
                if( strcmp((car+i)->license_id,value) == 0 ){
                    return (car+i);
                }
            }
    }
    return NULL;
}


void print_car(struct Car* car){
            if(car->is_empty){
                printf("car is empty\n");
            }else {
            /* init the string with zero*/
                printf("color:\t%s\n",(car)->color);
                printf("price:\t%d\n",(car)->current_price);
                printf("engine capcity\t%d\n",(car)->engine_capacity);
                printf("freme number:\t%s\n",(car)->frame_id);
                printf("license number:\t%s\n",(car)->license_id);
                printf("manufacturer name:\t%s\n",(car)->manufacturer_name);
                printf("model name:\t%s\n",(car)->model_name);
                printf("road rising year :\t%d\n",(car)->road_raising_year);
                printf("supplier_price:\t%d\n",(car)->supplier_price);
                printf("year of relase:\t%d\n\n",(car)->year_of_relase);
            }  
}

void print_car_list(struct Car* car){
    for(int i = 0 ; i <  N ; i++){
        printf("index in array:\t%d\n",i);
        print_car(car+i);
    }     
}

// delte car cy id number
int deleteCar(struct Car* car,char* license_id){
    // do we need to move all the valus of array backword  ?
    struct Car* res = searchBy_license_id(car,license_id);
    if(res != NULL ){
        deleteSingleCar(res);
        return 0 ;
    }
    return -1 ; 
}

// delete all cars 
int deleteAllCars(struct Car* car){
    if(car == NULL ){printf("list is empty\n");return -1;}
    for(int i = 0 ; i < N && (car+i) != NULL ; i++){
        deleteSingleCar(car+i); 
    }
    car = NULL ; 
    return 0 ; 
}

void deleteSingleCar(struct Car* car){
        strcpy((car)->color,"");
        (car)->current_price = 0;
        (car)->engine_capacity = 0;
        strcpy((car)->frame_id,"");
        strcpy((car)->license_id,"");
        strcpy((car)->manufacturer_name,"");
        strcpy((car)->model_name,"");
        (car)->road_raising_year = 0;
        (car)->supplier_price = 0;
        (car)->year_of_relase = 0;
        (car)->is_empty = 1;
} 