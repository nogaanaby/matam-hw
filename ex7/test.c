#include "test.h" 

void run_test_car(){
    /* test for createCarTree */
    Tree *tree = createCarsTree(); 
    print_prompt(" test : create car Tree ");
    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
    addCarToTree(tree);
    /* print list  */
    printCarTree(tree);
    
    {
        int count = 0 ; 
        print_prompt(" test : carNumberWithGivenCapacity_REC (2000)  ");
        count = carNumberWithGivenCapacity_REC(tree->root,2000);
        printf("\tnumber  of cars with engine value  of 2000 is : %d\n",count);
    }

    print_prompt(" test : searchBy_license_id (1234574)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        int res_count = -1 ; 
        Node *res = NULL ;
        res = FindCarInTreeByid(tree,1234574);
        if(res){
             print_car(res,res_count);
        }else{
            print_prompt("car not found");
        }
    }
  
    print_prompt(" test : delete single car (car id = 1234570)  ");
    printf("\n"); 
    {
     removeCarFromTree(tree,1234570);
     printf("\n");
     printCarTree(tree);
     printf("\n");
    } 

    printf("\n");
    print_prompt(" test : delete all cars (destroyCarTree)  ");
    destroyCarTree(tree);
    printf("\n");
}

void run_suppliers_test(){
    /* test for createCarTree */
    Tree *tree = createSuppliersTree(); 
    print_prompt(" test : create suppliers Tree ");
    /* test for  addNewCar*/
    print_prompt(" test : add new supplier ");
    addNewSupplier(tree);
    addNewSupplier(tree);
    addNewSupplier(tree);
    /* print list  */
    print_sup_Tree(tree);
    print_prompt(" test : searchBy suppliers id (12350)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        Node *res = NULL ;
        res = FindSupInTreeByid(tree->root,"12350");
        if(res){
            print_sup(res,0);
        }else{
            print_prompt("car not found");
        }
    }
    
  /*   print_prompt(" test : average Of Supplier Money ");
    {   
        int res = averageOfSupplierMoney(tree);
        if(res != -1){
            printf("sum of avrege transaction is : %d\n" ,res);
        }
    }
 */

    printf("\n");
    print_prompt(" test : delete all suppliers (destroyCarTree)  ");
    DeleteAllSuppliers(tree);
    printf("\n");

}

void run_clients_test(){
    int id=1234567;
    int *idptr=&id;
    Tree *clients=createClientsTree();
    addNewClient(clients);
    addNewClient(clients);
    addNewClient(clients);
    /*add_example_clients(clients);*/
    print_clients(clients);


    deleteClient(clients,idptr);

    printf("******************* after delete client 1234567 ***************** \n");
    print_clients(clients);

    deleteAllClients(clients);
    printf("******************* after delete all clients ***************** \n");
    print_clients(clients);

}


void add_example_clients(Tree *cl){
    char *noga="noga\0";
    char *anaby="anaby\0";
    char *tamir="tamir\0";
    char *bar="bar\0";
    addNewClient_test(cl,noga, anaby, 1234567, 1326454,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, 7984615, 1234567,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, 4987264, 5555555,44,2005,12,1,15,20);
    addNewClient_test(cl,tamir, bar, 7789245, 2222222,44,2004,12,1,15,20);
    addNewClient_test(cl,tamir, bar, 2222222, 9999999,44,2004,12,1,15,20);        
}


/* helpar  function to priont prompt  */

void print_prompt(char *text){
    printf("\n");
    printf("\t----%s----\t",text);
    printf("\n");
}
