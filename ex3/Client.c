#include "Client.h"
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
 int addNewClient(Clients_List* clients_list){
    Client_Node* new_client_node;
    Client* new_client;
    new_client_node = (Client_Node *) malloc(sizeof(Client_Node));
    new_client = (Client *) malloc(sizeof(Client));

    get_client_input_from_user(new_client);
    new_client_node->client = new_client;
    new_client_node->next = clients_list->head;
    clients_list->head = new_client_node;
    clients_list->size_count+=1;
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
    Client_Node *current = head;

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

/* delete all Client */ 
int deleteAllClients(Clients_List *clients_list){
    int i = 0;
    if(clients_list == NULL ){
        printf("list is empty\n");
        return -1;
    }
    while(clients_list->head!= NULL){
        deleteClient(clients_list,clients_list->head->client->id );
    } 
    return 0 ; 
}

int deleteClient(Clients_List* clients_list, char* id) {
    int i = 0;
    Client_Node * current = clients_list->head;
    Client_Node * client_node_to_delete = NULL;

    /*no clients on the list*/
    if(current==NULL){
        return -1;
    }
    /*if its the head of the list*/
    if(strcmp(current->client->id,id)==0){
        free(current->client);
        if(current->next!=NULL){
            clients_list->head=current->next;
        }else{
            clients_list->head=NULL;
        }
        free(current);
        clients_list->size_count-=1;
        return 0;
    }

    for (i = 0; i < clients_list->size_count; i++) {
        if(current->next){
            if(strcmp(current->next->client->id,id)==0 ){
                free(current->next->client);
                client_node_to_delete = current->next;
                /*if its not the end of the list I want that the prev node will point the next node: prev->client_to_delete->next*/
                if (current->next->next) {
                    current->next=current->next->next;
                }else{/*it is the end of the list*/
                    current->next=NULL;
                }
                free(client_node_to_delete);
                clients_list->size_count-=1;
                return 0;
            }
        }
        current = current->next;
    }
    /*if the id wasnt in the list*/
    return -1;
}

int addNewClient_test(Clients_List* clients_list,char *first_name, char *last_name, char *id, int car_license_id, 
    int price_per_hour, int year, int month, int day, int hour, int minutes){
        Client_Node* cnode1=(Client_Node *) malloc(sizeof(Client_Node));
        Client* new_client=(Client *) malloc(sizeof(Client));

        strcpy(new_client->first_name, first_name);
        strcpy(new_client->last_name, last_name);
        strcpy(new_client->id, id);
        
        new_client->car_license_id=car_license_id;
        new_client->price_per_hour=price_per_hour;
        new_client->start_rent_date.year=year;
        new_client->start_rent_date.month=month;
        new_client->start_rent_date.day=day;
        new_client->start_rent_time.hour=hour;
        new_client->start_rent_time.minutes=minutes;

        cnode1->client=new_client;
        cnode1->next=clients_list->head;
        clients_list->head = cnode1;
        clients_list->size_count+=1;
        return 0; 
}