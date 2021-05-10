#ifndef CLIENT_H 
#define CLIENT_H

#include <stdio.h>

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
     char first_name[MAX_LEN_NAME];
     char last_name[MAX_LEN_NAME];
     char id[MAX_LEN_SEVEN]; 
     char car_license_id[MAX_LEN_SEVEN];
     int price_per_hour;
     struct Date start_rent_date;
     struct Time start_rent_time;
}Client;





// create array of clients with stdin input M , set the fildes to zero 
int createClientsList(struct Client* cli);

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
 struct Client* addNewClient();

// sarch for cars in data base 
 struct Client* searchBy( struct Client* cli, char attr[], char* value);

// delte car cy id number
int deleteClient(char* client_id);

// delete all cars 
int deleteAllClients();
void print_client(struct Client* cli);


#endif