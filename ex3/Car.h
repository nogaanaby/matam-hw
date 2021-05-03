#ifndef CAR.H 
#define CAR
#define MAX_LEN_TEN 10 
#define MAX_LEN_FOUR  4 
#define MAX_LEN_SEVEN 7
#define MAX_LEN_FIVE 5
#define N 10000 

#include<stdio.h>
#include<string.h>

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
};


// create array of cars fix size N, set the fildes to zero 
int createCarList(struct Car* carsList);

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
struct Car* addNewCar(char* license_id, char frame_id[], char manufacturer_name[],char model_name[],
char color[],int year_of_relase, int road_raising_year, 
int supplier_price, int current_price, int engine_capacity);

// sarch for cars in data base 
struct Car* searchBy( struct Car* car, char attr[], char* value);

// delte car cy id number
int deleteCar(char* license_id);

// delete all cars 
int deleteAllCars(struct Car* carsList);

#endif
