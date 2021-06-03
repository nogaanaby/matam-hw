 

#ifndef CAR_H
#define CAR_H
#include "Supplier.h"
#define MAX_LEN_TEN 10 
#define MAX_LEN_FOUR  4 
#define MAX_LEN_SEVEN 7
#define MAX_LEN_FIVE 5
#define N 3




typedef struct Car
{
    int license_id;
    int frame_id;
    char manufacturer_name[MAX_LEN_TEN];
    char model_name[MAX_LEN_TEN];
    char color[MAX_LEN_SEVEN];
    int year_of_relase;
    int road_raising_year;
    int supplier_price;
    int current_price;
    int engine_capacity;
}Car;





/*create array of cars fix size N, set the fildes to zero */ 
int createCarTree(struct Car* carsList);
/* add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
 3. return error if in array */ 
int addNewCar(struct Car *car_list,struct Supplier *s);
/*splite addNewCar into 3 function 1.input 2. valid input => (inside file io.h) 3. add to array */
int get_input_from_user(struct Car *temp_car,struct Supplier *s);
int addCarToTree(struct Car *car,struct Car *car_list);
/* sarch for cars in data base */ 
struct Car* searchBy_license_id( struct Car* car, int value);
int carNumberWithGivenCapacity( struct Car* car, int value);

/* print car and car list */
void print_car(struct Car* car);
void print_car_Tree(struct Car* car);
/* make adeep copy of car objrct */
int  copy_car(struct Car *to,struct Car *from); 
/* delte car by engine value */
int deleteCar(struct Car* car,int license_id);
/* delete all cars */
int deleteAllCars(struct Car* carsList);
void deleteSingleCar(struct Car* c); 

#endif
