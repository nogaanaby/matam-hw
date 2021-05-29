#include "test.h"


int main(){
    {
        run_test_car();
    }

    run_clients_test();
    run_suppliers_test();
    run_clients_and_cars_test();
   
    return 0;
}
     

