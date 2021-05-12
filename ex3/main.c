#include "Car.h"
#include "Supplier.h"
#include "test.h"
#include <stdio.h>
#include "Client.h"


int main(){
    struct Car list_car[N];
    struct Client clients_list[3];
    struct Supplier bugest_three_sup[3];
    struct Supplier sup_list[K];
    print_Welcome_prompt();
    {
            
        run_test_supplier(sup_list,bugest_three_sup);
    }
    /*start test car*/
    {
        run_test_car(list_car,sup_list);
    }
    /*start test sup*/
    run_clients_test(clients_list,sup_list);
    run_clients_and_cars_test(clients_list,list_car,sup_list);
 
    return 0;
}
     

