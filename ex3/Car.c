
#include "car.h"


/* create linked list of cars  */ 

 
/* chenge is_empty to false*/
/*splite into 3 function 1. get_input 2. check input 3. 
return car and put into array in index  */
  
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



/* sarch for cars in data base, return pointer from struct */ 

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

/* delte car by id number*/

/* delete all cars */
