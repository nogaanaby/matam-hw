#include "test.h" 

// void run_test_supplier(struct Supplier* list_sup){
//     int i = 0;
//     createSuppliersList(list_sup);

//     print_prompt(" print Supplier list ");
//     print_sup_list(list_sup);
    
    
//     print_prompt(" test : BIGEST THREE SUPLIERS ");
//     int ids_arr[3];
//     threeGreatestSuppliers(list_sup,ids_arr);
//     for(int i=0;i<3;i++){
//         printf("%d \n", ids_arr[i]);
//     }

//     // {
//     //     struct Supplier *s; 
//     //     print_prompt(" test : search Supplier in list by id (1234567891) ");
//     //     s = searchBy_Supplier_id(list_sup,1234567891);
//     //     print_prompt(" print search result ");
//     //     if(s)
//     //         print_sup(s);
//     //     else
//     //         print_prompt(" not found "); 
//     // }
    
//     // {
//     //     print_prompt(" test : delete Supplier from list with id (1234567891) ");
//     //     deleteSupplier(list_sup,1234567891);
//     //     print_prompt(" print Supplier list ");
//     //     print_sup_list(list_sup);

//     // }

    
//}


// void run_test_car(){
//     List **list_car ; 
//     int i = 0;
//     print_prompt(" test : create car list ");
//     /* test for createCarList */ 
//     *list_car = createCarList();
//     printCarList(*list_car);

//     /* test for  addNewCar*/
//     print_prompt(" test : add new car ");
//     for( i = 0 ; i < 2 ; i++)
//         addCarToList(list_car);
//         addCarToList(list_car);
//         addCarToList(list_car);
//     printCarList(*list_car);


//     /*test carNumberWithGivenCapacity*/
// /*     print_prompt(" test : carNumberWithGivenCapacity (2000)  ");

//  */ 
//     print_prompt(" test : searchBy_license_id (1234567)");
//     printf("\n");
//     /*test searchBy_license_id*/
//     {
//         struct Car *res ;
//         res = FindCarInListById(list_car,1234567);
//         if(res){
//              printCarList(res);
//         }
//     }
//     print_prompt(" test : delete single car  ");
//     printf("\n");
//     /*test for delete single car */
//     {
//     removeCarFromList(list_car,1234567);
//     printCarList(list_car);
//     printf("\n");
//     }

//     printf("\n");
//     destroyCarList(list_car);
//     printCarList(list_car);
//     printf("\n");

// }

  
// void run_clients_and_cars_test(){
//     Clients_List* cll=createClientsList();
//     add_example_clients(cll);
//     // List* cal=createCarsList();
//     // add_example_clients(cal);
//     // int cli= clientNumberWithGivenCarYear(2004, cll,cal);
//     // printf("there are %d clients who have cars from %d", cli, 2004);
// }

void run_clients_test(){
    Clients_List* cl=createClientsList();
    add_example_clients(cl);
    //addNewClient(&cl->head);

    //deleteAllClients(clients_list);

    print_clients_list(cl->head);
    printf("\n");

    printf("------------------------after insert clients data--------------------\n");
    char *id="7984615";
    deleteClient(cl,id);

    print_clients_list(cl->head);
    printf("\n");
}


void add_example_clients(Clients_List *cl){
    char *noga="noga\0";
    char *anaby="anaby\0";
    char *idn="1234567\0";
    addNewClient_test(cl,noga, anaby, idn, 1326457,44,2004,12,1,15,20);

    char *tamir="tamir\0";
    char *bar="bar\0";
    char *idt="7984615\0";
    addNewClient_test(cl,tamir, bar, idt, 1326457,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 1326457,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 1326457,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 1326457,44,2004,12,1,15,20);        
}


void run_suppliers_test(){
    Suppliers_List* sl=createSuppliersList();
    add_example_suppliers(sl);
    //addNewClient(&cl->head);
    print_sup_list(sl->head);
    printf("\n");

    //char *supid="4444444444";
    //deleteSupplier(sl,supid);
    //char sup_id[3][11]={"1234567890", "1987465947","1653978465"};
    char sup_id[3][11];
    char *supidptr=sup_id[0];
    // printf("suppliers ids array: ");
    // for (int i=0;i<3;i++) {
    //     //add the licens
    //     printf("supidptr+i =%s, ",(supidptr+i));
    // }
    // printf("\n");

    printf("------------before threeGreatestSupplier_REC---------------\n");

    threeGreatestSupplier_REC(sl,supidptr);
    printf("threeGreatestSupplier_REC: ");
    for(int i=0;i<3;i++){
        printf(" %s ,",(supidptr+i));
    }
    printf("\n");
    //print_sup_list(sl->head);
}


void add_example_suppliers(Suppliers_List *sl){
    char *misubitchi="misubitchi\0";
    char *id1="1234567890\0";
    addNewSupplier_test(sl,id1,misubitchi,1234567891,44,2400);

    char *toyota="toyota\0";
    char *id2="2222222222\0";
    addNewSupplier_test(sl,id2,toyota,1234567891,10,50000);

    char *zibi="zibi\0";
    char *id3="3333333333\0";
    addNewSupplier_test(sl,id3, zibi,1234567891,10,80000);
        
    char *zibi1="zibi1\0";
    char *id4="4444444444\0";
    addNewSupplier_test(sl,id4, zibi1,1234567891,10,2);

    char *zibi2="zibi2\0";
    char *id5="5555555555\0";
    addNewSupplier_test(sl,id5, zibi2,1234567891,10,90000);
}

