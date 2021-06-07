
#ifndef CAR_H
#define CAR_H
#include "utils.h"

#define MAX_LEN_TEN 10 
#define MAX_LEN_FOUR  4 
#define MAX_LEN_SEVEN 7
#define MAX_LEN_FIVE 5
#define ALLOC 0 

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

typedef struct Node {
	Car* car;
	struct Node* left;
	struct Node* right;
    int sum_of_sub_tree_left;
    int sum_of_sub_tree_right; 
} Node;

/* wrapper for a tree node */
typedef struct {
	Node* root;
	int elementCount;
} BinarySearchTree;

/* enum for types of tree traversal */
typedef enum { INORDER, PREORDER, POSTORDER } Traversal;




/*create linked list  of cars   */ 
BinarySearchTree* createCarTree();
/* add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
 3. return error if in array */ 
void addCarToTree(BinarySearchTree *tree);
/* helper func */
Node* insertNodeToTree( Node *root, Node* new_node);
void get_input_from_user(struct Car* temp_car);
/* find car in linked  list by id val  */
struct Node* FindCarInTreeByid(Node* head,int id);
/* print car and car list */
void printCarTree(BinarySearchTree *tree);
void printCarTree_rec(Node *root,int *coun);
void print_car(struct Car* car,int *coun);
/* query */
int carNumberWithGivenCapacity_REC(Node *head,int engine_val);
/* delete car by id value */
/* int removeCarFromTree(Node** head,int id);
 */
void destroyCarTree(BinarySearchTree* tree);
void destroyTree(BinarySearchTree* tree);
void destroyTree_REC(Node *head);
void free_car(Node* tmp);
/* helperfunc*/
void get_car_test();
#endif