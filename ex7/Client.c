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
    if(node1==NULL || node2==NULL){
        return -2;
    }else{
        Client* cli2=node2->value;
        Client* cli1=node1->value;
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
    get_chr_input("Please enter (20 digit) client first name:\t",temp_client->first_name,MAX_LEN_NAME);
    get_chr_input("Please enter (20 digit) client last name:\t",temp_client->last_name,MAX_LEN_NAME);
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
    if(node!=NULL){
        Client *client=node->value;
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
    printf("line=%d \n",__LINE__);
    Node *current = clients_tree->root;
    Client *c=current->value;
    while(current != NULL){
        printf("line=%d \n",__LINE__);
        c=current->value;
        if( c->id == *id){
            return current;
        } else if(c->id > *id){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    printf("line=%d \n",__LINE__);
    printf("client does not found");
    return NULL;
}



void pushClientToList(Clients_List_Node *current, Client *cli){
    Client *temp;
    if(current==NULL){
        current->client=cli;
    }
    else if (current->client->id < cli->id)
        pushClientToList(current->next,cli);
    else{
        temp=current->client;
        current->client=cli;
        pushClientToList(current->next,temp);
    }
}

void findClientsByDate(Node *current, Clients_List_Node *head, Date *date){
    if(current != NULL){
        Client *c=current->value;
        if( c->start_rent_date.year == date->year &&
            c->start_rent_date.month == date->month &&
            c->start_rent_date.day == date->day ){
            pushClientToList(head,c);
        }
        findClientsByDate(current->left,head->next,date);
        findClientsByDate(current->right,head->next,date);
    }
}

void findClient(Tree *clients_tree,Clients_List_Node *head, int *id, Date *date){
    Node *current = clients_tree->root;
    Node *this;
    if(id!=NULL){
        this= findClientById(clients_tree,id);
        head->client=this->value;
    }else{
        findClientsByDate(current,head,date);
    }
}
// int clientNumberWithGivenCarYear(int year, Clients_Tree *clients_tree,Car_Tree *cars_tree){
//     int count=0;
//     Client_Node *current_client = clients_tree->root;
//     Car_Node *current_car = cars_tree->root;
//     while(current_client != NULL){
//         while(current_car != NULL){
//             if(current_car->car->license_id==current_client->client->car_license_id
//                 && current_car->car->year_of_relase==year){
//                     count++;
//             }
//             current_car=current_car->left;
//         }
//         current_car = cars_tree->root;
//         while(current_car != NULL){
//             if(current_car->car->license_id==current_client->client->car_license_id
//                 && current_car->car->year_of_relase==year){
//                     count++;
//             }
//             current_car=current_car->right;
//         }
//         current_client=current_client->left;
//     }
//     current_client= clients_tree->root->right;
//     while(current_client != NULL){
//         while(current_car != NULL){
//             if(current_car->car->license_id==current_client->client->car_license_id
//                 && current_car->car->year_of_relase==year){
//                     count++;
//             }
//             current_car=current_car->left;
//         }
//         current_car = cars_tree->root;
//         while(current_car != NULL){
//             if(current_car->car->license_id==current_client->client->car_license_id
//                 && current_car->car->year_of_relase==year){
//                     count++;
//             }
//             current_car=current_car->right;
//         }
//         current_client=current_client->right;
//     }
//     return count;
// }




int deleteAllClients(Node *current){
    if(current==NULL){
        return 0;
    }else if(current->left==NULL &&current->right==NULL){
        free(current->value);
        free(current);
        return 0;
    } 
    if(current->left!=NULL){
        deleteAllClients(current->left);
    }
    if(current->right!=NULL){
        deleteAllClients(current->right);
    }
}


/* Function to delete the given node */
int deleteClient(Tree* tree, int* id){
    printf("line=%d \n",__LINE__);
    Node *cnode=findClientById(tree,id);
    printf("client to remove: line(%d) \n",__LINE__);
    print_client(cnode,0);
    if(cnode!=NULL){
        int removed=removeNode(tree,tree->root,cnode,theSecond_IsLarger_ByClientId);
        printf("removed=%d: \n",removed);   
        if(removed==0){
            return 0;
        }
    }
        return -1;
}




// int addNewClient_test(Clients_Tree* clients_tree,char *first_name, char *last_name, int id, int car_license_id, 
//     int price_per_hour, int year, int month, int day, int hour, int minutes){
//         Client_Node* cnode1=(Client_Node *) malloc(sizeof(Client_Node));
//         Client* new_client=(Client *) malloc(sizeof(Client));
//         Client_Node* current;

//         strcpy(new_client->first_name, first_name);
//         strcpy(new_client->last_name, last_name);
//         new_client->id= id;
        
//         new_client->car_license_id=car_license_id;
//         new_client->price_per_hour=price_per_hour;
//         new_client->start_rent_date.year=year;
//         new_client->start_rent_date.month=month;
//         new_client->start_rent_date.day=day;
//         new_client->start_rent_time.hour=hour;
//         new_client->start_rent_time.minutes=minutes;

//         cnode1->client=new_client;
//         cnode1->left=NULL;
//         cnode1->right=NULL;
//         current=clients_tree->root;
        
//         if(current==NULL){
//             clients_tree->root=cnode1;

//         }else{
//             while(current != NULL){
//                 if(current->client->id > new_client->id){
//                     if(current->left ==NULL){
//                         current->left=cnode1;
//                         break;
//                     }else{
//                         current = current->left;
//                     }
//                 }else{
//                     if(current->right ==NULL){
//                         current->right=cnode1;
//                         break;
//                     }else{
//                         current = current->right;
//                     }
//                 }
//             }
//         }
//         clients_tree->elementCount+=1;
  
//         return 0;
// }
