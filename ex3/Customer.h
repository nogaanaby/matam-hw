#ifndef CUSTOMER.H 
#define CUSTOMER.H

#include<stdio.h>

#define MAX_LEN_NAME 20 
#define MAX_LEN_FOUR 4
#define MAX_LEN_ID 9
#define MAX_LEN_SEVEN 7 
#define MAX_LEN_COST 5

typedef struct Date{
    int day;
    char manth[MAX_LEN_FOUR];
    int year;
};

typedef struct Time{
    int minutes;
    int hour;
};

typedef struct Customer{
     char first_name[MAX_LEN_NAME];
     char last_name[MAX_LEN_NAME];
     char id[MAX_LEN_SEVEN]; 
     char car_license_id[MAX_LEN_SEVEN];
     struct Date start_rent_date;
     struct Time start_rent_time;
     int price_per_hour;
};





// create array of cluint with stdin input M , set the fildes to zero 
struct Customer* createCustomer();

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
 struct Customer* addNewCustomer(char first_name[], );

// sarch for cars in data base 
 struct CarCustomers* SarchCustomer( struct Customer* C);

// delte car cy id number
void deleteCustomer(char* Customer_id);

// delete all cars 
void deleteAllCustomer();


#endif