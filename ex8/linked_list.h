
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
	char* data;
	struct Node* next;
} Node;

void addToList(Node** head, const char* str);
void printList(Node* head);
char* pop_data_and_remove(Node** head);
void removeFirstFromList(Node** head);
void destroyList(Node** head);
int countListElements(Node* head);

typedef struct {
	Node* head;
	int count;
} List;

void ListAdd(List* list, const char* str);
#endif