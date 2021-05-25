#include "Client.h" 
#include "Utils.h"
int count_array_index = 0;
/* create array of client with stdin input M , set the fildes to zero */ 
Clients_List* createClientsList(){
    Clients_List *new_list = (Clients_List*) malloc(sizeof(Clients_List));
    int i = 0, m;
    if(new_list == NULL ){
        printf("error list is empty\n");
    }else{
        new_list->head = NULL; 
        new_list->size_count = 0 ; 
        return new_list;
    }

}

/* add a new Client to array of Client = > 1.check for this Client in data 2.find the pleace in array 
 3. return Utils if in array */ 
 int addNewClient(Client_Node** head){
    Client_Node* new_client_node;
    Client* new_client;
    new_client_node = (Client_Node *) malloc(sizeof(Client_Node));
    new_client = (Client *) malloc(sizeof(Client));

    get_client_input_from_user(new_client);
    new_client_node->client = new_client;
    new_client_node->next = *head;
    *head = new_client_node;
    return 0; 
 }

int get_client_input_from_user(struct Client *temp_client){
    get_chr_input("Please enter (20 digit) client first name:\t",temp_client->first_name,MAX_LEN_NAME);
    get_chr_input("Please enter (20 digit) client last name:\t",temp_client->last_name,MAX_LEN_NAME);
    get_chr_input("Please enter (7 digit) client id:\t",temp_client->id,MAX_LEN_SEVEN);
    while(*temp_client->id=='0'){
        printf("ID can not be 0 \n");
        get_chr_input("Please enter (7 digit) client id:\t",temp_client->id,MAX_LEN_SEVEN);
    }
    
    get_int_input("Please enter (7 digit) car_license_id:\t",&temp_client->car_license_id,MAX_LEN_SEVEN);
    get_int_input("Please enter price_per_hour:\t",&temp_client->price_per_hour,4);
    get_int_input("Please enter start rent year (4 digits):\t",&temp_client->start_rent_date.year,4);
    get_int_input("Please enter start rent month (2 digits):\t",&temp_client->start_rent_date.month,2);
    get_int_input("Please enter start rent day (2 digits):\t",&temp_client->start_rent_date.day,2);
    get_int_input("Please enter start rent hour (2 digits between 0-23):\t",&temp_client->start_rent_time.hour,2);
    get_int_input("Please enter start rent minutes (2 digits between 0-59):\t",&temp_client->start_rent_time.minutes,2);

    return 0; 
}


void print_client(struct Client* client){
    printf("first_name:\t%s\n",(client)->first_name);
    printf("last_name:\t%s\n",(client)->last_name);
    printf("id \t%s\n",(client)->id);
    printf("car_license_id :\t%d\n",(client)->car_license_id);
    printf("price_per_hour :\t%d\n",(client)->price_per_hour);
    printf("start_rent_date :\t%d.%d.%d\n",(client)->start_rent_date.day,(client)->start_rent_date.month,(client)->start_rent_date.year);
    printf("start_rent_time :\t%d:%d\n",(client)->start_rent_time.hour,(client)->start_rent_time.minutes);
}

void print_clients_list(Client_Node * head){
    Client_Node * current = head;

    while (current != NULL) {
        print_client(current->client);
        current = current->next;
    }
}

// int clientNumberWithGivenCarYear(int year, struct Car *cars_list, struct Client *clients_list){
//     int count=0;
//     int i = 0;
//     struct Car *temp_car;
//     int temp_license_id;
//     while(*(clients_list+i)->id!=0){
//         temp_license_id=(clients_list+i)->car_license_id;
//         temp_car = searchBy_license_id(cars_list,temp_license_id );
//         if(temp_car!=NULL){
//             if((temp_car)->year_of_relase==year){
//                 count++;
//             }
//         }
//         i++;
//     } 
//     return count;
// }


// /* delte Client by id number*/
// int deleteClient(char* client_id,struct Client *clients_list){
//     int i = 0;
//     while(*(clients_list+i)->id!=0 ){
//         if((clients_list+i)->id==client_id){
//             strcpy((clients_list+i)->first_name,"");
//             strcpy((clients_list+i)->last_name,"");
//             strcpy((clients_list+i)->id,"");
//             (clients_list+i)->car_license_id=0;
//             (clients_list+i)->price_per_hour =0;
//             (clients_list+i)->start_rent_date.year =0;
//             (clients_list+i)->start_rent_date.month =0;
//             (clients_list+i)->start_rent_date.day =0;
//             (clients_list+i)->start_rent_time.hour =0;
//             (clients_list+i)->start_rent_time.minutes =0;
//             return 0;
//         }
//         i++;
//     } 
//     return -1;

// }

// /* delete all Client */ 
// int deleteAllClients(struct Client *clients_list){
//     int i = 0;
//     if(clients_list == NULL ){printf("list is empty\n");return -1;}
//     while(*(clients_list+i)->id!=0){
//         deleteClient( (clients_list+i)->id,clients_list );
//         i++;
//     } 
//     return 0 ; 
// }

