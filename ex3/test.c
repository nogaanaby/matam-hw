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



void run_test_car(){
    Node *list_car = NULL ; 
    print_prompt(" test : create car list ");
    /* test for createCarList */

    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
        addCarToList(&list_car);
        addCarToList(&list_car);
        addCarToList(&list_car);
        addCarToList(&list_car);
        addCarToList(&list_car);
        addCarToList(&list_car);
    printCarList(list_car);


    /*test carNumberWithGivenCapacity*/
/*     print_prompt(" test : carNumberWithGivenCapacity (2000)  ");

 */ 
  /*   print_prompt(" test : sort linked list ");
    sort_by_munifucter_year(list_car);
    print_prompt("after sort");
    printCarList(list_car);
 */


    print_prompt(" test : searchBy_license_id (1234568)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        struct Car *res = NULL ;
        struct Node *prev = NULL;
        res = FindCarInListById(list_car,prev,1234567+1);
        if(res){
             print_car(res);
        }
    }
    print_prompt(" test : delete single car  ");
    printf("\n");
    /*test for delete single car */
    {
    removeCarFromList(list_car,1234568);
    printf("\n");
    printCarList(list_car);
    printf("\n");
    }
    printf("\n");
    print_prompt(" test : delete all cars  ");
    destroyCarList(list_car);
    printCarList(list_car);
    printf("\n");

}

  
// void run_clients_and_cars_test(struct Client* clients_list,struct Car* cars_list,struct Supplier* list_sup){
//     int cli = 0;
//     fill_in_clients_list(clients_list);
//     fill_in_cars_list(cars_list,list_sup);
//     cli= clientNumberWithGivenCarYear(2004, cars_list, clients_list);
//     printf("there are %d clients who have cars from %d", cli, 2004);
// }

void run_clients_test(){
    printf("\n");
    Clients_List* cl=createClientsList();
    add_example_clients(cl);
    //addNewClient_test(cl,&("tamir"), &("bar"), &("3184759"), 7586524,44,2004,12,1,15,20);
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
    char *noga="noga";
    char *anaby="anaby";
    char *idn="1234567";
    addNewClient_test(cl,noga, anaby, idn, 1326457,44,2004,12,1,15,20);

    char *tamir="tamir";
    char *bar="bar";
    char *idt="7984615";
    addNewClient_test(cl,tamir, bar, idt, 1326457,44,2004,12,1,15,20);
}


void print_prompt(char *text){
    printf("\n");
    printf("\t---- %s ----\n",text);
    printf("\n");   
}
