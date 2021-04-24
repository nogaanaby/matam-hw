#ifndef CLIENT.H 
#define CLIENT.H

#include<stdio.h>

#define MAX_LEN_NAME 20 
#define MAX_LEN_FOUR 4
#define MAX_LEN_ID 9
#define MAX_LEN_SEVEN 7 
#define MAX_LEN_COST 5

typedef struct Date{
    int day;
    int month;
    int year;
};

typedef struct Time{
    int minutes;
    int hour;
};

typedef struct Client{
     char first_name[MAX_LEN_NAME];
     char last_name[MAX_LEN_NAME];
     char id[MAX_LEN_SEVEN]; 
     char car_license_id[MAX_LEN_SEVEN];
     struct Date start_rent_date;
     struct Time start_rent_time;
     int price_per_hour;
};





// create array of clients with stdin input M , set the fildes to zero 
int createClientsList(struct Client* cli);

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
 struct Client* addNewClient(char first_name[],char last_name[],char* id,char car_license_id[],
 int year,int month, int day,int hour,int minutes,int price_per_hour);

// sarch for cars in data base 
 struct Client* searchBy( struct Client* cli, char attr[], char* value);

// delte car cy id number
int deleteClient(char* client_id);

// delete all cars 
int deleteAllClients();


#endif