#include "test.h" 

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
    removeCarFromList(list_car,1234569);
    printf("\n");
    printCarList(list_car);
    printf("\n");
    }
    printf("\n");
    print_prompt(" test : delete all cars (destroyCarList)  ");
    destroyCarList(&list_car);
    printCarList(list_car);
    printf("\n");
}

  
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


void print_prompt(char *text){
    printf("\n");
    printf("\t---- %s ----\n",text);
    printf("\n");   
}

void run_suppliers_test(){
    Suppliers_List* sl=createSuppliersList();
    add_example_suppliers(sl);
    //addNewClient(&cl->head);
    print_sup_list(sl->head);
    printf("\n");
    char *sup_ids;
    printf("------------before threeGreatestSupplier_REC---------------\n");

    threeGreatestSupplier_REC(sl,sup_ids);
    printf("threeGreatestSupplier_REC: ");
    printf("%s", sup_ids);
    printf("\n");
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

