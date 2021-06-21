#include "Client.h"


/* create array of client with stdin input M , set the fildes to zero */ 
Tree* createClientsTree(){
    return createTree();
}

/* add a new Client to array of Client = > 1.check for this Client in data 2.find the pleace in array 
 3. return Utils if in array */ 
void createClient(Node *node){
    Client *new_client=(Client *) malloc(sizeof(Client));
    get_client_input_from_user(new_client);
    node->value=new_client;
}

unsigned int theSecond_IsLarger_ByClientId(Node *node1,Node *node2){
    Client* cli2;
    Client* cli1;
    if(node1==NULL || node2==NULL){
        return -2;
    }else{
        cli2=node2->value;
        cli1=node1->value;
        if(cli1->id < cli2->id){
            return 1;
        }else if(cli1->id > cli2->id){
            return -1;
        }else{
            return 0;
        }
    }
}

 int addNewClient(Tree* clients_tree){
    return addNewNode(clients_tree,createClient,theSecond_IsLarger_ByClientId);
 }

int get_client_input_from_user(Client *temp_client){
    get_chr_input("Please enter (20 digit) client first name:\t",temp_client->first_name,ALLOC);
    get_chr_input("Please enter (20 digit) client last name:\t",temp_client->last_name,ALLOC);
    get_int_input("Please enter (7 digit) client id:\t",&temp_client->id,MAX_LEN_SEVEN);
    while(temp_client->id==0){
        printf("ID can not be 0 \n");
        get_int_input("Please enter (7 digit) client id:\t",&temp_client->id,MAX_LEN_SEVEN);
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


void print_client(Node* node,int tubsNum){
    Client *client;
    if(node!=NULL){
        client=node->value;
        printtabs(tubsNum);
        printf("first_name:\t%s\n",(client)->first_name);
        printtabs(tubsNum);
        printf("last_name:\t%s\n",(client)->last_name);
        printtabs(tubsNum);
        printf("id \t%d\n",(client)->id);
        printtabs(tubsNum);
        printf("car_license_id :\t%d\n",(client)->car_license_id);
        printtabs(tubsNum);
        printf("price_per_hour :\t%d\n",(client)->price_per_hour);
        printtabs(tubsNum);
        printf("start_rent_date :\t%d.%d.%d\n",(client)->start_rent_date.day,(client)->start_rent_date.month,(client)->start_rent_date.year);
        printtabs(tubsNum);
        printf("start_rent_time :\t%d:%d\n",(client)->start_rent_time.hour,(client)->start_rent_time.minutes);
    }else{
        printf("client was not found \n");
    }

}

void print_clients(Tree *tree){
    printtree_rec(tree->root,0,print_client);
}



Node* findClientById(Tree *clients_tree, int *id){
    Node *current = clients_tree->root;
    Client *c=current->value;
    while(current != NULL){
        c=current->value;
        if( c->id == *id){
            return current;
        } else if(c->id > *id){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    printf("client does not found");
    return NULL;
}



void pushClientToList(List_Node *current, Client *cli){
    Client *temp;
    if(current==NULL){
        current->value=cli;
        return;
    }
    temp=current->value;
    if (temp->id < cli->id){
        pushClientToList(current->next,cli);
    }else{
        current->value=cli;
        pushClientToList(current->next,temp);
    }
}

void findClientsByDate(Node *current, List_Node *head, Date *date){
    Client *c;
    if(current != NULL){
        c=current->value;
        if( c->start_rent_date.year == date->year &&
            c->start_rent_date.month == date->month &&
            c->start_rent_date.day == date->day ){
            pushClientToList(head,c);
        }
        findClientsByDate(current->left,head->next,date);
        findClientsByDate(current->right,head->next,date);
    }
}

void findClient(Tree *clients_tree,List_Node *head, int *id, Date *date){
    
    Node *current = clients_tree->root;
    Node *this;
    if(id!=NULL){
        this= findClientById(clients_tree,id);
        head->value=this->value;
    }else{
        findClientsByDate(current,head,date);
    }
}
// int clientNumberWithGivenCarYear(int year, Tree *clients_tree,Tree *cars_tree){
//     int count=0;
//     Node *current_client_node = clients_tree->root;
//     Node *current_car_node = cars_tree->root;
//     Client *current_client = current_client_node->value;
//     Car *current_car = current_car_node->value;

//     while(current_client_node != NULL){
//         while(current_car_node != NULL){
//             if(current_car->license_id==current_client->car_license_id
//                 && current_car->year_of_relase==year){
//                     count++;
//             }
//             current_car_node=current_car_node->left;
//         }
    //     current_car_node = cars_tree->root;
    //     while(current_car_node != NULL){
    //         if(current_car->license_id==current_client->car_license_id
    //             && current_car->year_of_relase==year){
    //                 count++;
    //         }
    //         current_car_node=current_car_node->right;
    //     }
    //     current_client_node=current_client_node->left;
    // }
//     current_client_node= clients_tree->root->right;
//     while(current_client_node!= NULL){
//         while(current_car != NULL){
//             if(current_car->license_id==current_client->car_license_id
//                 && current_car->year_of_relase==year){
//                     count++;
//             }
//             current_car_node=current_car_node->left;
//         }
//         current_car_node = cars_tree->root;
//         while(current_car_node != NULL){
//             if(current_car->license_id==current_client->car_license_id
//                 && current_car->year_of_relase==year){
//                     count++;
//             }
//             current_car_node=current_car_node->right;
//         }
//         current_client_node=current_client_node->right;
//     }
//     return count;
// }
// void printClientCarsForGivenRentDate(Node *current,Date *date){
//     Client *cli;
//     if(current!=NULL){
//         cli=current->value;
//         if(cli->start_rent_date.year==date->year&&
//             cli->start_rent_date.month==date->month&&
//             cli->start_rent_date.day==date->day
//         ){
//             print_client(current,0);
//         }
//         printClientCarsForGivenRentDate(current->left,date);
//         printClientCarsForGivenRentDate(current->right,date);
//     }
// }

void freeClientAttr(Node *node){
    Client *toRemove=node->value;
    free(toRemove->first_name);
    free(toRemove->last_name);
}

int deleteAllClients(Tree *tree){
    freeTree(tree->root,freeClientAttr);
    tree->root=NULL;
    return 0;
}


/* Function to delete the given node */
int deleteClient(Tree* tree, int* id){
    Node *cnode=findClientById(tree,id);
    freeClientAttr(cnode);
    if(cnode!=NULL){
        int removed=removeNode(tree,tree->root,cnode,theSecond_IsLarger_ByClientId);
        if(removed==0){
            return 0;
        }
    }
        return -1;
}




int addNewClient_test(Tree* clients_tree,char *first_name, char *last_name, int id, int car_license_id, 
    int price_per_hour, int year, int month, int day, int hour, int minutes){
        Node* cnode1=(Node *) malloc(sizeof(Node));
        Client* new_client=(Client *) malloc(sizeof(Client));
        Node* current;
        Client *cli;

        new_client->first_name=(char*)malloc(strlen(first_name)+1);
        strcpy(new_client->first_name, first_name);
        new_client->last_name=(char*)malloc(strlen(last_name)+1);
        strcpy(new_client->last_name, last_name);
        new_client->id= id;
        
        new_client->car_license_id=car_license_id;
        new_client->price_per_hour=price_per_hour;
        new_client->start_rent_date.year=year;
        new_client->start_rent_date.month=month;
        new_client->start_rent_date.day=day;
        new_client->start_rent_time.hour=hour;
        new_client->start_rent_time.minutes=minutes;

        cnode1->value=new_client;
        cnode1->left=NULL;
        cnode1->right=NULL;
        current=clients_tree->root;
        
        if(current==NULL){
            clients_tree->root=cnode1;

        }else{
            while(current != NULL){
                cli=current->value;
                if(cli->id > new_client->id){
                    if(current->left ==NULL){
                        current->left=cnode1;
                        break;
                    }else{
                        current = current->left;
                    }
                }else{
                    if(current->right ==NULL){
                        current->right=cnode1;
                        break;
                    }else{
                        current = current->right;
                    }
                }
            }
        }
        clients_tree->elementCount+=1;
  
        return 0;
}
