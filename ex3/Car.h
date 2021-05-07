#ifndef CAR_H
#define CAR_H
#define MAX_LEN_TEN 10 
#define MAX_LEN_FOUR  4 
#define MAX_LEN_SEVEN 7
#define MAX_LEN_FIVE 5
#define N 30

#include<stdio.h>
#include<string.h>
enum type{int_,char_};

typedef struct Car
{
    char license_id[MAX_LEN_SEVEN];
    char frame_id[MAX_LEN_FIVE];
    char manufacturer_name[MAX_LEN_TEN];
    char model_name[MAX_LEN_TEN];
    char color[MAX_LEN_SEVEN];
    int year_of_relase;
    int road_raising_year;
    int supplier_price;
    int current_price;
    int engine_capacity;
    int is_empty ; 
}Car;


// create array of cars fix size N, set the fildes to zero 
int createCarList(struct Car* carsList);
// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
struct Car addNewCar();
//splite addNewCar into 3 function 1.input 2. valid input => (inside file io.h) 3. add to array 
struct Car get_input_from_user();
int addCarToArray(struct Car car);
// sarch for cars in data base 
struct Car* searchBy_license_id( struct Car* car, char* value);
struct Car* searchBy_engine_capacity( struct Car* car, char* value);
// print car and car list 
void print_car(struct Car* car);
void print_car_list(struct Car* car);
// delte car by engine value
int deleteCar(struct Car* car,char* license_id);
// delete all cars 
int deleteAllCars(struct Car* carsList);
void deleteSingleCar(struct Car* c); 

#endif
