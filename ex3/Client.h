#ifndef CLIENT_H 
#define CLIENT_H

#include "Car.h"
#define MAX_LEN_NAME 20 
#define MAX_LEN_FOUR 4
#define MAX_LEN_ID 9
#define MAX_LEN_SEVEN 7 
#define MAX_LEN_COST 5
#define NUM 3

static int count_array_index = 0;

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
     char first_name[MAX_LEN_NAME];
     char last_name[MAX_LEN_NAME];
     char id[MAX_LEN_SEVEN]; 
     char car_license_id[MAX_LEN_SEVEN];
     int price_per_hour;
     struct Date start_rent_date;
     struct Time start_rent_time;
}Client;



// create array of clients with stdin input M , set the fildes to zero 
int createClientsList(struct Client* clientsList);

// add a new client to array of client = > 1.check for this client in data 2.find the pleace in array 
// 3. return error if in array 
int addNewClient(struct Client *clientsList);

int get_client_input_from_user(struct Client *temp_client);
int addClientToArray(struct Client *client,struct Client *clientsList);
int copy_client(struct Client *to,struct Client *from); 

void print_client(struct Client* cli);
void print_clients_list(struct Client* clientsList);

// sarch for client in data base 
//struct Client* searchBy( struct Client* cli, char attr[], char* value);
int clientNumberWithGivenCarYear(int year, struct Car *cars_list, struct Client *client_list);

// delte client cy id number
int deleteClient(char* client_id);

// delete all client 
int deleteAllClients(struct Client *clients_list);

#endif