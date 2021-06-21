
#ifndef CAR_H
#define CAR_H
#define MAX_LEN_TEN 10 
#define MAX_LEN_FOUR  4 
#define MAX_LEN_SEVEN 7
#define MAX_LEN_FIVE 5
#define ALLOC 0 

#include "utils.h"
#include "BinaryTree.h"

typedef struct Car
{
    int license_id;
    int frame_id;
    /* alloceted  fields  */
    char *manufacturer_name;
    char *model_name;
    char *color;
    /* alloceted  fields  */
    int year_of_relase;
    int road_raising_year;
    int supplier_price;
    int current_price;
    int engine_capacity;
    int is_empty ; 
}Car;


/* wrapper for a tree node */


/* enum for types of tree traversal */
typedef enum { INORDER, PREORDER, POSTORDER } Traversal;

/*create tree of cars   */ 
Tree* createCarsTree();
/* add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
 3. return error if in array */ 
int addCarToTree(Tree *tree);
unsigned int compere_tow_cars(Node* car1,Node* car2);
void createCar(Node *new_node);
/* helper func */
void get_input_from_user(struct Car* temp_car);
/* find car in linked  list by id val  */
int removeCarFromTree(Tree *tree,int id);
int carNumberWithGivenCapacity_REC(Node *head, int engine_val);
Node* FindCarInTreeByid(Tree* tree,int id);
void destroyCarTree(Tree *tree);
/* print car and car list */
void printCarTree(Tree *tree);
void print_car(Node *node,int count);
/* query */

#endif