
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
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
	struct Car *car;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	unsigned int size_count;
} List;




/*create linked list  of cars   */ 
List* CreateCarList();
/* add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
 3. return error if in array */ 
void addCarToList(Node** head);
/* helper func */
int addCarToLinkedList(struct Node **head,struct Node* car_node);
void get_input_from_user(struct Car* temp_car);
/* find car in linked  list by id val  */
struct Car* FindCarInListById(Node* head,int id);
Node* get_prev(Node* head,struct Car* car);
void destroyCarList(Node** head);
/* print car and car list */
void printCarList(Node* head);
void print_car(struct Car* car);
/* delte car by id value */
int removeCarFromList(Node** head,int id);
void destroyCarList(Node** head);
void free_car(Node* tmp);

#endif