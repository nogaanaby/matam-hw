#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "Car.h"

#define N 30 



int main(){
    /* test for car */
    struct Car list_car[N]; 
    createCarList(list_car);
    print_car_list(list_car);
    struct Car c = addNewCar();
    print_Car(c);
    printf("\n");
    return 0;
}