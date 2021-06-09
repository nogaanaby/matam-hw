#include "test.h" 

void run_test_car(){
    /* test for createCarTree */
    Car_Tree *tree = createCarsTree(); 
    print_prompt(" test : create car Tree ");
    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
    addCarToTree(tree);
    addCarToTree(tree);
    addCarToTree(tree);
    addCarToTree(tree);
    addCarToTree(tree);
    addCarToTree(tree);
    addCarToTree(tree);
    addCarToTree(tree);
    /* print list  */
    printCarTree(tree);
    
    {
        int count = 0 ; 
        print_prompt(" test : carNumberWithGivenCapacity_REC (2000)  ");
        count = carNumberWithGivenCapacity_REC(tree->root,2000);
        printf("\tnumber  of cars with engine value  of 2000 is : %d\n",count);
    }



    print_prompt(" test : searchBy_license_id (1234570)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        int res_count = -1 ; 
        Car_Node *res = NULL ;
        res = FindCarInTreeByid(tree->root,1234570);
        if(res){
             print_car(res->car,&res_count);
        }else{
            print_prompt("car not found");
        }
    }
   /*  
    print_prompt(" test : delete single car (car id = 1234570)  ");
    printf("\n"); 
    {
     removeCarFromTree(tree,1234570);
     printf("\n");
     printCarTree(tree);
     printf("\n");
    } 
 */
    printf("\n");
    print_prompt(" test : delete all cars (destroyCarTree)  ");
    destroyCarTree(tree);
    printf("\n");
}

void print_prompt(char *text){
    printf("\n");
    printf("\t----%s----\t",text);
    printf("\n");
}



void run_suppliers_test(){
    /* test for createCarTree */
    Suppliers_Tree *tree = createSuppliersList(); 
    print_prompt(" test : create car Tree ");
    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
    addNewSupplier(tree);
    addNewSupplier(tree);
    addNewSupplier(tree);
    addNewSupplier(tree);
    addNewSupplier(tree);
    addNewSupplier(tree);
    /* print list  */
    print_sup_Tree(tree->root);
    

    print_prompt(" test : searchBy_license_id (1234570)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        Supplier_Node *res = NULL ;
        res = FindSupInTreeByid(tree->root,"1234570");
        if(res){
             print_sup(res->supplier);
        }else{
            print_prompt("car not found");
        }
    }
    printf("\n");
    print_prompt(" test : delete all cars (destroyCarTree)  ");
    deleteAllSuppliers(tree);
    printf("\n");

}

void run_clients_test1(){
    Clients_Tree* cTree=createClientsTree();
    addNewClient(cTree);
    print_clients(cTree);
    addNewClient(cTree);
    print_clients(cTree);
    free(cTree);
}

void run_clients_test2(){
    Clients_Tree* cTree=createClientsTree();
    //add_example_clients(cTree);
    //print_clients(cTree);

    int id=1234567;
    int *idptr=&id;
    print_client(findClientById(cTree, idptr),0);

    free(cTree);
}

void run_clients_test3(){
    Clients_Tree* cTree=createClientsTree();
    addNewClient(cTree);
    print_clients(cTree);
    free(cTree);
}

void add_example_clients(Clients_Tree *cl){
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