#include "Client.h" 
#include "Utils.h"

// create array of cluint with stdin input M , set the fildes to zero 
int createClientsList(struct Client* cli){
    // to do 
}

// add a new Client to array of Client = > 1.check for this Client in data 2.find the pleace in array 
// 3. return Utils if in array 
 struct Client* addNewClient(){
    char first_name[MAX_LEN_NAME], last_name[MAX_LEN_NAME],*id, car_license_id[MAX_LEN_SEVEN];
    int year, month,  day, hour, minutes, price_per_hour;
    struct Client* temp_client;
    
    get_chr_input("Please enter (20 digit) client first name",first_name,MAX_LEN_NAME);
    strcpy((temp_client)->first_name,first_name);

    strcpy((temp_client)->last_name,"boo");
    strcpy((temp_client)->id,"1234567");
    strcpy((temp_client)->car_license_id,"1234567");

    return temp_client; 
 }
void print_client(struct Client* client){
            //if(car->is_empty){
            //    printf("car is empty\n");
            //}else {
            /* init the string with zero*/
                printf("first_name:\t%s\n",(client)->first_name);
                printf("last_name:\t%d\n",(client)->last_name);
                printf("id \t%d\n",(client)->id);
                printf("car_license_id :\t%s\n",(client)->car_license_id);
             
            //}  
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

