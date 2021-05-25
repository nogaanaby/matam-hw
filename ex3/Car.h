 

#ifndef CAR_H
#define CAR_H
#include "Supplier.h"
#define MAX_LEN_TEN 10 
#define MAX_LEN_FOUR  4 
#define MAX_LEN_SEVEN 7
#define MAX_LEN_FIVE 5
#define ALLOC 0 




typedef struct Car
{
    int license_id;
    int frame_id;
    /* alloceted  fields  */
    char *manufacturer_name;
    char *model_name;
    char *color;
    /* alloceted  fields  */
    int year_of_relase;
    int road_raising_year;
    int supplier_price;
    int current_price;
    int engine_capacity;
    int is_empty ; 
}Car;


/*create array of cars fix size N, set the fildes to zero */ 
/* add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
 3. return error if in array */ 
/* sarch for cars in data base */ 
/* print car and car list */
void print_car(struct Car* car);
/* make adeep copy of car objrct */
int  copy_car(struct Car *to,struct Car *from); 
/* delte car by engine value */
#endif
