
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
void addCarToList(Node** head);
/* helper func */
int addCarToLinkedList(struct Node **head,struct Node* car_node);
void get_input_from_user(struct Car* temp_car);
/* find car in linked  list by id val  */
struct Node* FindCarInListById(Node* head,int id);
/* print car and car list */
void printCarList(Node* head);
void print_car(struct Car* car);
/* query */
void inverseCarList(Node** head);
int carNumberWithGivenCapacity(Node *head,int engine_val);
int carNumberWithGivenCapacity_REC(Node *head,int engine_val);
/* delte car by id value */
int removeCarFromList(Node** head,int id);
void destroyCarList(Node** head);
void free_car(Node* tmp);
/* helperfunc*/
void sort_by_year_of_relase(struct Node *head);
void repalce( Node *target, Node* source );
Node* getPrev(Node* head, int id);
void get_car_test();
int addNewCar_test(BinarySearchTree* cars_list,char *manufacturer_name, char *model_name, char *color, 
    int license_id, int frame_id, int year_of_relase, int road_raising_year, int supplier_price, 
    int current_price, int engine_capacity);
#endif