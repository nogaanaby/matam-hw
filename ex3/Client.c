#include "Client.h" 
#include "Car.h" 
#include "Utils.h"

// create array of cluint with stdin input M , set the fildes to zero 
int createClientsList(struct Client* client){
    if(client == NULL ){
        printf("error list is empty\n");
        return -1;
    }
        for(int i = 0 ; i < NUM; i++){
            /* init the string with zero*/
            strcpy((client+i)->first_name,"");
            strcpy((client+i)->last_name,"");
            strcpy((client+i)->id,"");
            strcpy((client+i)->car_license_id,"");
            
            (client+i)->price_per_hour =0;
            (client+i)->start_rent_date.year =0;
            (client+i)->start_rent_date.month =0;
            (client+i)->start_rent_date.day =0;
            (client+i)->start_rent_time.hour =0;
            (client+i)->start_rent_time.minutes =0;

        }
    return 0;
}

// add a new Client to array of Client = > 1.check for this Client in data 2.find the pleace in array 
// 3. return Utils if in array 
 int addNewClient(struct Client* clients_list){
    Client temp_client;
    get_client_input_from_user(&temp_client);
    addClientToArray(&temp_client,clients_list);
    return 0; 
 }

int get_client_input_from_user(struct Client *temp_client){
    get_chr_input("Please enter (20 digit) client first name:\t",temp_client->first_name,MAX_LEN_NAME);
    get_chr_input("Please enter (20 digit) client last name:\t",temp_client->last_name,MAX_LEN_NAME);
    get_chr_input("Please enter (7 digit) client id:\t",temp_client->id,MAX_LEN_SEVEN);
    get_chr_input("Please enter (7 digit) car_license_id:\t",temp_client->car_license_id,MAX_LEN_SEVEN);

    get_int_input("Please enter price_per_hour:\t",&temp_client->price_per_hour,4);
    get_int_input("Please enter start rent year (4 digits):\t",&temp_client->start_rent_date.year,4);
    get_int_input("Please enter start rent month (2 digits):\t",&temp_client->start_rent_date.month,2);
    get_int_input("Please enter start rent day (2 digits):\t",&temp_client->start_rent_date.day,2);
    get_int_input("Please enter start rent hour (2 digits between 0-23):\t",&temp_client->start_rent_time.hour,2);
    get_int_input("Please enter start rent minutes (2 digits between 0-59):\t",&temp_client->start_rent_time.minutes,2);

    return 0; 
}

int copy_client(struct Client *to,struct Client *from){
    if(from && to){
            strcpy((to)->first_name,from->first_name);
            strcpy((to)->last_name,from->last_name);
            strcpy((to)->id,from->id);
            strcpy((to)->car_license_id,from->car_license_id);

            (to)->price_per_hour =from->price_per_hour;
            (to)->start_rent_date.year =from->start_rent_date.year;
            (to)->start_rent_date.month =from->start_rent_date.month;
            (to)->start_rent_date.day =from->start_rent_date.day;
            (to)->start_rent_time.hour =from->start_rent_time.hour;
            (to)->start_rent_time.minutes =from->start_rent_time.minutes;
            return 0 ;                      
    }
    return -1 ;
} 

int addClientToArray(struct Client *client,struct Client *clients_list){
    if(client && clients_list){
        copy_client(clients_list+count_array_index,client);
        printf("add new client to array in index %d \n",count_array_index);
        count_array_index++;
        return 0; 
    }
    return -1; 
}

void print_client(struct Client* client){
    printf("first_name:\t%s\n",(client)->first_name);
    printf("last_name:\t%s\n",(client)->last_name);
    printf("id \t%s\n",(client)->id);
    printf("car_license_id :\t%s\n",(client)->car_license_id);

    printf("price_per_hour :\t%d\n",(client)->price_per_hour);
    printf("start_rent_date :\t%d.%d.%d\n",(client)->start_rent_date.day,(client)->start_rent_date.month,(client)->start_rent_date.year);
    printf("start_rent_time :\t%d:%d\n",(client)->start_rent_time.hour,(client)->start_rent_time.minutes);
}
void print_clients_list(struct Client* client){
    for(int i = 0 ; i < NUM; i++){
        printf("index in array:\t%d\n",i);
        print_client(client+i);
    }     
}

int clientNumberWithGivenCarYear(int year, struct Car *cars_list, struct Client *client_list){
    //go to each client -> car_license_id
    int count=0;
    struct Car myCar;
    for(int i = 0 ; i < NUM ; i++){
        struct Car *temp_car = searchBy_license_id( (client_list+i)->car_license_id )
        if(temp_car!=NULL){
            if((temp_car)->year_of_relese==year){
                count++;
            }
        }

    } 
    return count;
    //searchBy_license_id(client_car_license_id)
    //check if the seach doesnt return null
    //check wether this car year_of_relase is the same year I looking for
    //if so, i count +1
    //struct Car* searchBy_license_id( struct Car* car, int value);
}

// sarch for Client in data base 
//  struct Client* searchBy( struct Client* cli, char attr[], char* value){
//     struct Client cli;
//     return &cli;
//  }

// delte Client by id number
int deleteClient(char client_id,struct Client *clients_list){
    for(int i = 0 ; i < NUM ; i++){
        if((clients_list+i)->id==client_id){
            free(clients_list+i);
            return 0;
        }
    } 
    return -1;
    // strcpy((client)->first_name,"");
    // strcpy((client)->last_name,"");
    // strcpy((client)->id,"");
    // strcpy((client)->car_license_id,"");
    
    // (client)->price_per_hour =0;
    // (client)->start_rent_date.year =0;
    // (client)->start_rent_date.month =0;
    // (client)->start_rent_date.day =0;
    // (client)->start_rent_time.hour =0;
    // (client)->start_rent_time.minutes =0;
}

// delete all Client 
int deleteAllClients(struct Client *clients_list){
    if(clients_list == NULL ){printf("list is empty\n");return -1;}
    for(int i = 0 ; i < NUM ; i++){
        deleteClient( (clients_list+i)->id,clients_list ); 
    } 
    return 0 ; 
}

