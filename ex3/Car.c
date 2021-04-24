
#include "car.h"

// create array of cars fix size N, set the fildes to zero 
int createCarList(struct Cars* carsList){
// to Do
    //check if the carsList has the correct types and size
        return 1;
    //return 0;
}

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
struct Cars* addNewCar(char* license_id, char frame_id[], char manufacturer_name[],char model_name[],
char color[],int year_of_relase, int road_raising_year, int supplier_price, int current_price, int engine_capacity){
// to Do
    struct Car* pointer_to_car_object; 
    return pointer_to_car_object;
}

// sarch for cars in data base 
struct Cars* searchBy(struct Cars* car, char attr[], char* value){
// to Do
    // loop->
    //     if(car_ptr.attr==value){
    //         return car_ptr;
    //     }
    struct Cars* pointer_to_car_in_array;
    return pointer_to_car_in_array;
}

// delte car cy id number
int deleteCar(char* license_id){
// to Do
}

// delete all cars 
int deleteAllCars(){
// to Do
}