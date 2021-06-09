
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

typedef struct Car_Node {
	Car* car;
	struct Car_Node* left;
	struct Car_Node* right;
    int sum_of_sub_tree_left;
    int sum_of_sub_tree_right; 
} Car_Node;

/* wrapper for a tree node */
typedef struct {
	Car_Node* root;
	int elementCount;
} Car_Tree;

/* enum for types of tree traversal */
typedef enum { INORDER, PREORDER, POSTORDER } Traversal;




/*create linked list  of cars   */ 
Car_Tree* createCarsTree();
/* add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
 3. return error if in array */ 
void addCarToTree(Car_Tree *tree);
/* helper func */
Car_Node* insertNodeToTree( Car_Node *root, Car_Node* new_node);
void get_input_from_user(struct Car* temp_car);
/* find car in linked  list by id val  */
int removeCarFromTree(Car_Tree *tree,int id);
void removeCarFromTree_REC(Car_Node * remove_node,Car_Node *root);
int carNumberWithGivenCapacity_REC(Car_Node *head, int engine_val);
Car_Node *get_father(Car_Node* root,Car_Node *node_to_remove, Car_Node* father);
Car_Node* FindCarInTreeByid(Car_Node* head,int id);
void destroyCarTree(Car_Tree *tree);
void destroyTree_REC(Car_Node *head);
/* print car and car list */
void printCarTree(Car_Tree *tree);
void printCarTree_rec(Car_Node *root,int *coun);
void print_car(struct Car* car,int *coun);
/* query */

#endif