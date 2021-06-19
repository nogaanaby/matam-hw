//#include "test.h"
#include "Client.h"


int main(){
    Tree *clients=createClientsTree();
    addNewClient(clients);
    print_clients(clients);

    // {
    //     run_test_car();
    // }
    // {
    //     run_suppliers_test();
    // }
    // run_clients_test1();
    /* run_suppliers_test();
     run_clients_and_cars_test();*/

    return 0;
}
     

