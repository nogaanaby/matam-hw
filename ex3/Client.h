#ifndef CLIENT_H 
#define CLIENT_H

#include "Car.h"
#include "Utils.h"
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
     char first_name[MAX_LEN_NAME+1];
     char last_name[MAX_LEN_NAME+1];
     int id; 
     int car_license_id;
     int price_per_hour;
     struct Date start_rent_date;
     struct Time start_rent_time;
}Client;

typedef struct Client_Node {
	Client *client;
	struct Client_Node* left;
    struct Client_Node* right;
} Client_Node;

typedef struct {
	Client_Node* root;
	int elementCount;
} Clients_Tree;


typedef struct Clients_List_Node {
	Client *client;
	struct Client_List_Node* next;
} Clients_List_Node;

/* create array of clients with stdin input M , set the fildes to zero */
Clients_Tree* createClientsTree();

/* add a new client to array of client = > 1.check for this client in data 2.find the pleace in array 
 3. return error if in array*/ 
int addNewClient(Clients_Tree* clients_tree);

int get_client_input_from_user(struct Client *temp_client);

void print_client(struct Client* cli);
void print_clients_list(Client_Node* root);

/* sarch for client in data base */
/*struct Client* searchBy( struct Client* cli, char attr[], char* value); */
/* int clientNumberWithGivenCarYear(int year, Clients_List *clients_list,List *cars_list);
 *//* delte client cy id number*/
Client_Node* deleteClient(Client_Node* root, int id);
int addNewClient_test(Clients_Tree* clients_tree,char *first_name, char *last_name, char *id, int car_license_id, 
    int price_per_hour, int year, int month, int day, int hour, int minutes);

/* delete all client */ 
int deleteAllClients(Clients_Tree* clients_tree);

#endif