
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "utils.h"
#include "car.h"

typedef struct Node {
	struct Car *car;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	unsigned int size_count;
} List;

List* CreateCarList();
struct Car* addCarToList(Node** head);
struct Car* FindCarInList(Node** head,int id);
/* helper func */
int addCarToLinkedList(struct Node **head,struct Node* car_node);
struct Car* FindCarInListById(Node* head,int id);
Node* get_prev(Node* head,Node* car);
void free_car(Node* tmp);
int removeCarFromList(Node** head,int id);
void destroyCarList(Node** head);
void get_input_from_user(struct Node* temp_car);
void printCarList(Node* head);
int removeCarFromList(Node** head,int id);
void destroyCarList(Node** head);

#endif