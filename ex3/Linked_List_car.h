
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct Node {
	struct Car *car;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	unsigned int size_count;
} List;

List* CreateCarList();
struct Car* addCarToList(Node** head, const struct Car *car);
struct Car* FindCarInList(Node** head,int id);
/* helper func */
int addCarToLinkedList(struct List *list_car);
void get_input_from_user(struct Node* temp_car);
void printCarList(Node* head);

int removeCarFromList(Node** head,int id);
void destroyCarList(Node** head);

#endif