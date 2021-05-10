#include "Client.h" 
#include "Utils.h"

// create array of cluint with stdin input M , set the fildes to zero 
int createClientsList(struct Client* cli){
    // to do 
    return 0;
}

// add a new Client to array of Client = > 1.check for this Client in data 2.find the pleace in array 
// 3. return Utils if in array 
 struct Client* addNewClient(){
    char first_name[MAX_LEN_NAME], last_name[MAX_LEN_NAME],id[MAX_LEN_SEVEN], car_license_id[MAX_LEN_SEVEN];
    int *year, *month, *day, *hour, *minutes, *price_per_hour;
    Client* temp_client;
    // Date* temp_date;
    // struct Time* temp_time;

    get_chr_input("Please enter (20 digit) client first name",first_name,MAX_LEN_NAME);
    strcpy((temp_client)->first_name,first_name);
    get_chr_input("Please enter (20 digit) client last name",last_name,MAX_LEN_NAME);
    strcpy((temp_client)->last_name,last_name);
    get_chr_input("Please enter (7 digit) client id",id,MAX_LEN_SEVEN);
    strcpy((temp_client)->id,id);
    get_chr_input("Please enter (7 digit) car_license_id",car_license_id,MAX_LEN_SEVEN);
    strcpy((temp_client)->car_license_id,car_license_id);

    //there`s still a problem with scannig the int input 
    get_int_input("Please enter price_per_hour",price_per_hour,4);
    (temp_client)->price_per_hour=*price_per_hour;

    get_int_input("Please enter (4 digit) year of start_rent_date",year,4);
    (temp_client)->start_rent_date.year=*year;
    get_int_input("Please enter (2 digit) month of start_rent_date",month,2);
    (temp_client)->start_rent_date.month=*month;
    get_int_input("Please enter (2 digit) day of start_rent_date",day,2);
    (temp_client)->start_rent_date.day=*day;

    get_int_input("Please enter (2 digit) minutes of start_rent_time",minutes,2);
    (temp_client)->start_rent_time.minutes=*minutes;
    get_int_input("Please enter (2 digit) hour of start_rent_date",hour,2);
    (temp_client)->start_rent_time.hour=*hour; 

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
     return cli;
 }

// delte Client by id number
int deleteClient(char* client_id){
    return 0;
}

// delete all Client 
int deleteAllClients(){
    return 0;
}

