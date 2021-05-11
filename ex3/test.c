#include "test.h" 

void run_test_supplier(struct Supplier* list_sup){
    int i = 0;
    {
        print_prompt(" test : create Supplier list, enter k = 3 for readble code test result ");
        createSuppliersList(list_sup);
        print_prompt(" print Supplier list ");
        print_sup_list(list_sup);
    }

    {
        print_prompt(" test : add Supplier to list ");
        for(i = 0 ; i < 2 ; i++)
            addNewSupplier(list_sup);
        print_prompt(" print Supplier list ");
        print_sup_list(list_sup);
    
    }

    {
        struct Supplier *s; 
        print_prompt(" test : search Supplier in list by id (1234567891) ");
        s = searchBy_Supplier_id(list_sup,1234567891);
        print_prompt(" print search result ");
        print_sup(s);
    }
    
    {
        print_prompt(" test : delete Supplier from list with id (1234567891) ");
        deleteSupplier(list_sup,1234567891);
        print_prompt(" print Supplier list ");
        print_sup_list(list_sup);

    }
    
    {
        print_prompt(" test : delete all supplier from list ");
        deleteAllSuppliers(list_sup);
        print_prompt(" print Supplier list ");
        print_sup_list(list_sup);
    }

    
}


void run_test_car(struct Car* list_car){
    int i = 0;
    print_prompt(" test : create car list ");
    /* test for createCarList */ 
    createCarList(list_car);
    print_cars(list_car);
    // print_car_list(list_car);

    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
    for( i = 0 ; i < 2 ; i++)
        addNewCar(list_car);
    print_cars(list_car);
    

    /*test carNumberWithGivenCapacity*/
    print_prompt(" test : carNumberWithGivenCapacity (2000)  ");
    printf("\n");
    {
    int resulet = carNumberWithGivenCapacity(list_car,2000);
    printf("res = %d \n",resulet);
    }

    print_prompt(" test : searchBy_license_id (1234567)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        struct Car *res ;
        res = searchBy_license_id(list_car,1234567);
        if(res){
             print_car(res);
        }
    }
    print_prompt(" test : delete single car  ");
    printf("\n");
    /*test for delete single car */
    {
    deleteCar(list_car,1234567);
    print_car_list(list_car);
    printf("\n");
    }

    print_prompt(" test : delete all cars  ");
    /*test for delete all cars */
    {
    printf("\n");
    deleteAllCars(list_car);
    print_car_list(list_car);
    printf("\n");
    }
}

void print_prompt(char* text){
    int i = 0 ; 
        printf("\n");
    for(i =0 ; i < 10 ;i++)
        printf("-");
    printf(" %s ",text);
    for( i = 0 ; i < 10 ;i++)
        printf("-");
    printf("\n");
}

void print_cars(struct Car *list_car){
    print_prompt(" print car list ");
    printf("\n");
    print_car_list(list_car);
}

void run_clients_test(struct Client* clients_list){
    createClientsList(clients_list);
    for(int i = 0 ; i < 2 ; i++){
        addNewClient(clients_list);
    }
    print_clients_list(clients_list);

    printf("------------------------after insert clients data--------------------\n");

    deleteClient((clients_list+0)->id,clients_list);

    print_clients_list(clients_list);
}