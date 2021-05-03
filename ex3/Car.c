
#include "car.h"

// create array of cars fix size N, set the fildes to zero 
int createCarList(struct Car* carsList){
// to Do
    //check if the carsList has the correct types and size
        if(carsList == NULL ){printf("error list is empty\n");return -1;}
        for(int i = 0 ; i <  N ; i++){
            /* init the string with zero*/
            strcpy((carsList+i)->color,"");
            (carsList+i)->current_price =0;
            (carsList+i)->engine_capacity =0;
            strcpy((carsList+i)->frame_id,"");
            strcpy((carsList+i)->license_id,"");
            strcpy((carsList+i)->manufacturer_name,"");
            strcpy((carsList+i)->model_name,"");
            (carsList+i)->road_raising_year = 0;
            (carsList+i)->supplier_price = 0;
            (carsList+i)->year_of_relase = 0;            
        }
    return 0;
}

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
struct Car* addNewCar(char* license_id, char frame_id[], char manufacturer_name[],char model_name[],
char color[],int year_of_relase, int road_raising_year, 
int supplier_price, int current_price, int engine_capacity){
// to Do
    struct Car* pointer_to_car_object; 
    return pointer_to_car_object;
}

// sarch for cars in data base 
struct Car* searchBy( struct Car* car, char attr[], char* value){
// to Do
    // loop->
    //     if(car_ptr.attr==value){
    //         return car_ptr;
    //     }
    struct Car* pointer_to_car_in_array;
    return pointer_to_car_in_array;
}

// delte car cy id number
int deleteCar(char* license_id){
// to Do
}

// delete all cars 
int deleteAllCars(struct Car* carsList){
    for(int i = 0 ; i < N && (carsList+i) != NULL ; i++){

    }
    return 0 ; 
}