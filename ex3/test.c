#include "test.h" 

void run_test_supplier(struct Supplier* list_sup){
    int i = 0;
    createSuppliersList(list_sup);

    print_prompt(" print Supplier list ");
    print_sup_list(list_sup);
    
    
    print_prompt(" test : BIGEST THREE SUPLIERS ");
    int ids_arr[3];
    threeGreatestSuppliers(list_sup,ids_arr);
    for(int i=0;i<3;i++){
        printf("%d \n", ids_arr[i]);
    }

    // {
    //     struct Supplier *s; 
    //     print_prompt(" test : search Supplier in list by id (1234567891) ");
    //     s = searchBy_Supplier_id(list_sup,1234567891);
    //     print_prompt(" print search result ");
    //     if(s)
    //         print_sup(s);
    //     else
    //         print_prompt(" not found "); 
    // }
    
    // {
    //     print_prompt(" test : delete Supplier from list with id (1234567891) ");
    //     deleteSupplier(list_sup,1234567891);
    //     print_prompt(" print Supplier list ");
    //     print_sup_list(list_sup);

    // }

    
}


void run_test_car(){
    List **list_car ; 
    int i = 0;
    print_prompt(" test : create car list ");
    /* test for createCarList */ 
    *list_car = createCarList();
    printCarList(*list_car);

    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
    for( i = 0 ; i < 2 ; i++)
        addCarToList(list_car);
        addCarToList(list_car);
        addCarToList(list_car);
    printCarList(*list_car);


    /*test carNumberWithGivenCapacity*/
/*     print_prompt(" test : carNumberWithGivenCapacity (2000)  ");
    printf("\n");
    {
    int resulet = carNumberWithGivenCapacity(list_car,2000);
    printf("res = %d \n",resulet);
    }

 */ 
    print_prompt(" test : searchBy_license_id (1234567)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        struct Car *res ;
        res = FindCarInListById(list_car,1234567);
        if(res){
             printCarList(res);
        }
    }
    print_prompt(" test : delete single car  ");
    printf("\n");
    /*test for delete single car */
    {
    removeCarFromList(list_car,1234567);
    printCarList(list_car);
    printf("\n");
    }

    print_prompt(" test : delete all cars  ");
    /*test for delete all cars */
    {
    printf("\n");
    destroyCarList(list_car);
    printCarList(list_car);
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
void print_Welcome_prompt(){
    int i = 0 ; 
    print_prompt("**-- Welcome --**");
    print_prompt(" this is a test of the partz car system programe please Follow the instructions ");
    for ( ; i < TEN - 7 ; i++){
        printf("\n");
    }
}

void print_cars(struct Car *list_car){
    print_prompt(" print car list ");
    printf("\n");
    print_car_list(list_car);
}
void fill_in_clients_list(struct Client* clients_list){
    int i = 0;
    createClientsList(clients_list);
    for( ; i < 3 ; i++){
        addNewClient(clients_list);
    }
    print_clients_list(clients_list);

}

void fill_in_cars_list(struct Car* cars_list,struct Supplier* list_sup){
    int i = 0;
    createCarList(cars_list);
    for( ; i < 3 ; i++){
        addNewCar(cars_list,list_sup);
    }
    print_cars(cars_list);
}


void run_clients_test(struct Client* clients_list,struct Supplier* list_sup){
    printf("\n");
    fill_in_clients_list(clients_list);

    printf("------------------------after insert clients data--------------------\n");

    deleteAllClients(clients_list);

    /*deleteClient((clients_list+0)->id,clients_list); */

    print_clients_list(clients_list);
    printf("\n");
}

void run_clients_and_cars_test(struct Client* clients_list,struct Car* cars_list,struct Supplier* list_sup){
    int cli = 0;
    fill_in_clients_list(clients_list);
    fill_in_cars_list(cars_list,list_sup);
    cli= clientNumberWithGivenCarYear(2004, cars_list, clients_list);
    printf("there are %d clients who have cars from %d", cli, 2004);
}