#include "Car.h"
#include "Supplier.h"
#include "test.h"
#include <stdio.h>
#include "Client.h"

void clients(){
    struct Client clients_list[N]; 
    createClientsList(clients_list);
    for(int i = 0 ; i < 2 ; i++){
        addNewClient(clients_list);
    }
    print_clients_list(clients_list);
}
// void cars(){
//     /* test for car */
//     struct Car list_car[N]; 
//     createCarList(list_car);
//     // print_car_list(list_car);
//     for(int i = 0 ; i < 2 ; i++)
//         addNewCar(list_car);
//     printf("\n");
//     for(int i =0 ; i < 10 ;i++)
//         printf("-");
//     printf(" print car list ");
//     for(int i =0 ; i < 10 ;i++)
//         printf("-");
//     printf("\n");
//     print_car_list(list_car);

//     // search  result  in array
//     struct Car *res ; 
//     //res = searchBy_engine_capacity(list_car,2000);
//     if(res){
//         print_car(res);
//     }
// }


int main(){
    /*start test car*/
    // {
    //     struct Car list_car[N];
    //     run_test_car(list_car);
    // }
    /*start test sup*/
    clients();
    // {
    //     struct Supplier sup_list[K];    
    //     run_test_supplier(sup_list);
    // }
    return 0;
}
     

