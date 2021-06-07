#include "test.h" 

void run_test_car(){
    /* test for createCarTree */
    BinarySearchTree *tree = createCarTree(); 
    print_prompt(" test : create car Tree ");
    /* test for  addNewCar*/
    print_prompt(" test : add new car ");
    addCarToTree(tree->root);
    addCarToTree(tree->root);
    addCarToTree(tree->root);
    addCarToTree(tree->root);
    addCarToTree(tree->root);
    /* print list  */
    printCarTree(tree->root);
    {
        int count = 0 ; 
        print_prompt(" test : carNumberWithGivenCapacity_REC (2000)  ");
        count = carNumberWithGivenCapacity_REC(tree->root,2000);
        printf("\tnumber  of cars with engine value  of 2000 is : %d\n",count);
    }



    print_prompt(" test : searchBy_license_id (1234568)");
    printf("\n");
    /*test searchBy_license_id*/
    {
        Node *res = NULL ;
        res = FindCarInTreeByid(tree->root,1234567+1);
        if(res){
             print_car(res->car);
        }
    }
/*     print_prompt(" test : delete single car (car id = 1234569)  ");
    printf("\n"); */
    /*test for delete single car */
 /*    {
     removeCarFromTree(&tree->root,1234569);
     printf("\n");
     printCarTree(tree->root);
     printf("\n");
    }
 */
    printf("\n");
    print_prompt(" test : delete all cars (destroyCarTree)  ");
    destroyCarTree(tree);
    printCarTree(tree->root);
    printf("\n");
}

void print_prompt(char *text){
    printf("\n");
    printf("\t----%s----\t",text);
    printf("\n");
}
