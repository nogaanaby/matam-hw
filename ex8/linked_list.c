#include "linked_list.h"


void addToList(Node** head, const char* str) {
	/*  *head  == NULL when first adding */
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = *head;
	newNode->data = (char*)malloc(strlen(str) + 1);
	strcpy(newNode->data, str);
	*head = newNode;
}

void printList(Node* head) {
	while (head) {
		printf("[%s]->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

void removeFirstFromList(Node** head) {
	if (*head) {
		Node* toDelete = *head;
		*head = (*head)->next;
		free(toDelete->data);
		free(toDelete);
	}
}
/* return the first Node data that in top of the list  than remove it */        
/*alloc space for date*/   
char* pop_data_and_remove(Node** head){
    char* temp_data = NULL;
    Node *temp_head = *head;
    if(temp_head){
        temp_data = (char*) malloc(sizeof(char) * strlen(temp_head->data));
        if(temp_data){
            strcpy(temp_data,temp_head->data);
            return temp_data;
        }
    }
    return NULL; 
}

void destroyList(Node** head) {
	while (*head) {
		removeFirstFromList(head);
	}
}

int countListElements(Node* head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

void ListAdd(List* list, const char* str) {
	/*  *head  == NULL when first adding */
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = list->head;
	newNode->data = (char*)malloc(strlen(str) + 1);
	strcpy(newNode->data,str);
	list->head = newNode;
	list->count++;
}