#ifndef CLIENT_H 
#define CLIENT_H

#include "Car.h"
#include "Utils.h"
#include "BinaryTree.h"
#define MAX_LEN_NAME 20 
#define MAX_LEN_FOUR 4
#define MAX_LEN_ID 9
#define MAX_LEN_SEVEN 7 
#define MAX_LEN_COST 5

typedef struct Date{
    int day;
    int month;
    int year;
}Date;

typedef struct Time{
    int minutes;
    int hour;
}Time;

typedef struct Client{
     char *first_name;
     char *last_name;
     int id; 
     int car_license_id;
     int price_per_hour;
     struct Date start_rent_date;
     struct Time start_rent_time;
}Client;


struct Tree* createClientsTree();
void createClient(struct Node *node);
int addNewClient(struct Tree* clients_tree);

int get_client_input_from_user(struct Client *temp_client);

void print_client(struct Node* node,int tubsNum);

void print_clients(struct Tree* tree);
void findClient(struct Tree *clients_tree,struct List_Node *head, int *id, Date *date);
/*int clientNumberWithGivenCarYear(int year, Tree *clients_tree,Tree *cars_tree);*/
void printClientCarsForGivenRentDate(struct Node *current,Date *date);
int deleteClient(struct Tree* tree, int *id);

int deleteAllClients(struct Tree* tree);
int addNewClient_test(struct Tree* clients_tree,char *first_name, char *last_name, int id, int car_license_id, 
    int price_per_hour, int year, int month, int day, int hour, int minutes);

#endif