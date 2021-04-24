#include "Client.h"

// create array of cluint with stdin input M , set the fildes to zero 
int createClientsList(struct Client* cli){
    // to do 
}

// add a new Client to array of Client = > 1.check for this Client in data 2.find the pleace in array 
// 3. return error if in array 
 struct Client* addNewClient(char first_name[],char last_name[],char* id,char car_license_id[],
 int year,int month, int day,int hour,int minutes,int price_per_hour){
     // to do 
 }

// sarch for Client in data base 
 struct Client* searchBy( struct Client* cli, char attr[], char* value){
     // to do 
 }

// delte Client by id number
int deleteClient(char* client_id){
    // to do 
}

// delete all Client 
int deleteAllClients(){
    // to do 
}

