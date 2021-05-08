#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "Car.h"
#include "Client.h"
#include "Client.c"

#define N 30 



int main(){
    /* test for car */
    // struct Car list_car[N]; 
    // createCarList(list_car);
    // print_car_list(list_car);

     struct Client *c = addNewClient();
     print_client(c);
    // printf("\n");
    return 0;
}