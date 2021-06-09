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
        Car_Node *res = NULL ;
        res = FindCarInTreeByid(tree->root,1234574);
        if(res){
             print_car(res->car,&res_count);
        }else{
            print_prompt("car not found");
        }
    }
  
 /*    print_prompt(" test : delete single car (car id = 1234570)  ");
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
    Suppliers_Tree *tree = createSuppliersTree(); 
    print_prompt(" test : create suppliers Tree ");
    /* test for  addNewCar*/
    print_prompt(" test : add new supplier ");
    addNewSupplier(tree);
    addNewSupplier(tree);
    addNewSupplier(tree);
    /* print list  */
    print_sup_Tree(tree->root);
    printf("sub left tree size : %d , sub right tree size : %d --- \n",tree->root->sum_of_sub_tree_left,tree->root->sum_of_sub_tree_right);
    printf("number of element in tree : %d\n",tree->elementCount);

    print_prompt(" test : searchBy suppliers id (12350)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        Supplier_Node *res = NULL ;
        res = FindSupInTreeByid(tree->root,"12350");
        if(res){
             print_sup(res->supplier);
        }else{
            print_prompt("car not found");
        }
    }
    
    print_prompt(" test : average Of Supplier Money ");
    {   
        int res = averageOfSupplierMoney(tree);
        if(res != -1){
            printf("sum of avrege transaction is : %d\n" ,res);
        }
    }


    printf("\n");
    print_prompt(" test : delete all suppliers (destroyCarTree)  ");
    deleteAllSuppliers(tree);
    printf("\n");

}
