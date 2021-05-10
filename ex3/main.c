#include "Car.h"
#include <stdio.h>
// #include "Client.h"

#define N 30 

int main(){
    /* test for car */
    struct Car list_car[N]; 
    createCarList(list_car);
    // print_car_list(list_car);
    struct Car c = addNewCar();
    //  struct Client *c = addNewClient();
    //  print_client(c);
    printf("\n");
    return 0;
}