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
