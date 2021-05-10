#include "Car.h"
#include <stdio.h>
#include "Client.h"


void clients(){
    struct Client c = addNewClient();
    print_client(&c);
}

int main(){
    clients();
    /* test for car */
    struct Car list_car[N]; 
    createCarList(list_car);
    // print_car_list(list_car);
    for(int i = 0 ; i < 2 ; i++)
        addNewCar(list_car);
    //  struct Client *c = addNewClient();
    //  print_client(c);
    printf("\n");
    for(int i =0 ; i < 10 ;i++)
        printf("-");
    printf(" print car list ");
    for(int i =0 ; i < 10 ;i++)
        printf("-");
    printf("\n");
    print_car_list(list_car);
    return 0;
}