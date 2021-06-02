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
    {
        int count = 0 ; 
        print_prompt(" test : carNumberWithGivenCapacity (2000)  ");
        count = carNumberWithGivenCapacity(list_car,2000);
        printf("\tnumber  of cars with engine value  of 2000 is : %d\n",count);
    }
    {
        int count = 0 ; 
        print_prompt(" test : carNumberWithGivenCapacity_REC (2000)  ");
        count = carNumberWithGivenCapacity_REC(list_car,2000);
        printf("\tnumber  of cars with engine value  of 2000 is : %d\n",count);
    }



    print_prompt(" test : searchBy_license_id (1234568)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        struct Node *res = NULL ;
        res = FindCarInListById(list_car,1234567+1);
        if(res){
             print_car(res->car);
        }
    }
    print_prompt(" test : delete single car (car id = 1234569)  ");
    printf("\n");
    /*test for delete single car */
    {
     removeCarFromList(&list_car,1234569);
     printf("\n");
     printCarList(list_car);
     printf("\n");
    }
    /*test for invarse list */
    {
        print_prompt(" test : invarse list  ");
        inverseCarList(&list_car);
        printf("\n");
        print_prompt("after inverse");
        printCarList(list_car);
        printf("\n");
    }


    printf("\n");
    print_prompt(" test : delete all cars (destroyCarList)  ");
    destroyCarList(&list_car);
    printCarList(list_car);
    printf("\n");
}

void run_clients_test(){
    Clients_List* cl=createClientsList();
    char *id="7984615";
    /*add_example_clients(cl);*/
    addNewClient(cl);

    /*deleteAllClients(clients_list);*/
    printf("------------------------after insert clients data--------------------\n");
    print_clients_list(cl->head);
    printf("\n");

    deleteClient(cl,id);
    print_clients_list(cl->head);
    printf("\n");
}


void add_example_clients(Clients_List *cl){
    char *noga="noga\0";
    char *anaby="anaby\0";
    char *idn="1234567\0";
    char *tamir="tamir\0";
    char *bar="bar\0";
    char *idt="7984615\0";
    addNewClient_test(cl,noga, anaby, idn, 1326454,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 1234567,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 5555555,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 2222222,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, idt, 9999999,44,2004,12,1,15,20);        
}


void print_prompt(char *text){
    printf("\n");
    printf("\t---- %s ----\n",text);
    printf("\n");   
}

void run_suppliers_test(){
    char* sup_ids= malloc(sizeof(sup_ids)); 
    Suppliers_List* sl=createSuppliersList();
    /*add_example_suppliers(sl);*/
    addNewSupplier(sl);
    print_sup_list(sl->head);
    printf("\n");
    printf("------------before threeGreatestSupplier_REC---------------\n");
    threeGreatestSupplier_REC(sl,sup_ids);
    printf("threeGreatestSupplier_REC: ");
    printf("%s", sup_ids);
    printf("\n");
}


void add_example_suppliers(Suppliers_List *sl){
    char *misubitchi="misubitchi\0";
    char *id1="1234567890\0";
    char *toyota="toyota\0";
    char *id2="2222222222\0";
    char *zibi="zibi\0";
    char *id3="3333333333\0";
    char *zibi1="zibi1\0";
    char *id4="4444444444\0";    
    char *zibi2="zibi2\0";
    char *id5="5555555555\0";    
    /*Suppliers_List* sup_list,char *id,char *name,int phone_number, 
  int count_transactions, int sum_of_total_transactions_price*/
    addNewSupplier_test(sl,id1,misubitchi,1234567891,44,2400);
    addNewSupplier_test(sl,id2,toyota,1234567891,10,50000);
    addNewSupplier_test(sl,id3, zibi,1234567891,10,80000);
    addNewSupplier_test(sl,id4, zibi1,1234567891,10,2);
    addNewSupplier_test(sl,id5, zibi2,1234567891,10,90000);
}

void run_clients_and_cars_test(){
    Clients_List* cl=createClientsList();
    List* carl=createCarList();
    add_example_clients(cl);
    print_clients_list(cl->head);
    add_example_cars(carl);
    printCarList(carl->head);
    printf("***********clientNumberWithGivenCarYear 2004 should be 2 *****************\n");
    printf(" %d \n", clientNumberWithGivenCarYear(2015,cl,carl) );
}

void add_example_cars(List *cl){
    char *misubitchi="misubitchi\0";
    char *x1model="x1model\0";
    char *white="white\0";
    addNewCar_test(cl,misubitchi,x1model,white,1234567,44,2004,2006,66000,70000,500);
    addNewCar_test(cl,misubitchi,x1model,white,5555555,44,2004,2006,66000,70000,500);
    addNewCar_test(cl,misubitchi,x1model,white,2222222,44,2015,2020,66000,70000,500);
    addNewCar_test(cl,misubitchi,x1model,white,9999999,44,2017,2020,66000,70000,500);

}
