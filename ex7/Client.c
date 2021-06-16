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

 int addNewClient(Tree* clients_tree){
    return addNewNode(clients_tree,createClient);
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


void print_client(struct Client* client,int tubsNum){
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
}

void print_clients(Tree *tree){
    printtree_rec(tree->root,0);
}

void printtabs(int numtabs){
    int i;
    for (i=0;i<numtabs;i++){
        printf("\t");
    }
}

void printtree_rec(Node *current, int level){
    if(current==NULL){
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }else{
        printtabs(level);
        print_client(current->value,level);
        printtabs(level);
        printf("left\n");

        printtree_rec(current->left,level+1);
        printtabs(level);
        printf("right\n");

        printtree_rec(current->right,level+1);

        printtabs(level);
    }

}

// void findClient(Clients_Tree *clients_tree,Clients_List_Node *head, int *id, Date *date){
//     Client_Node *current = clients_tree->root;
//     Client *this;
//     if(id!=NULL){
//         this= findClientById(clients_tree,id);
//         head->client=this;
//     }else{
//         findClientsByDate(current,head,date);
//     }
// }

// Client* findClientById(Clients_Tree *clients_tree, int *id){
//     Client_Node *current = clients_tree->root;
//     while(current != NULL){
//         if( current->client->id == *id){
//             return current->client;
//         } else if(current->client->id > *id){
//             current = current->left;
//         }else{
//             current = current->right;
//         }
//     }
//     return NULL;
//     printf("client does not found");
// }

// void findClientsByDate(Client_Node *current, Clients_List_Node *head, Date *date){
//     if(current != NULL){
//         if( current->client->start_rent_date.year == date->year &&
//             current->client->start_rent_date.month == date->month &&
//             current->client->start_rent_date.day == date->day ){
//             pushClientToList(head,current->client);
//         }
//         findClientsByDate(current->left,head->next,date);
//         findClientsByDate(current->right,head->next,date);
//     }
// }

// void pushClientToList(Clients_List_Node *current, Client *cli){
//     Client *temp;
//     if(current==NULL){
//         current->client=cli;
//     }
//     else if (current->client->id < cli->id)
//         pushClientToList(current->next,cli);
//     else{
//         temp=current->client;
//         current->client=cli;
//         pushClientToList(current->next,temp);
//     }
// }

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


// /* delete all Client */ 
// int deleteAllClients(Clients_Tree *clients_tree){
//     if(clients_tree == NULL ){
//         printf("tree is empty\n");
//         return -1;
//     }
//     while(clients_tree->root!= NULL){
//         deleteClient(clients_tree->root,clients_tree->root->client->id);
//     } 
//     return 0 ; 
// }


//  Client_Node* minValueNode(Client_Node* node)
// {
//     Client_Node* current = node;
//     /* loop down to find the leftmost leaf */
//     while (current->left != NULL)
//         current = current->left;
//     return current;
// }


// /* Function to delete the given node */
// Client_Node* deleteClient(Client_Node* root, int id)
//     {
//     Client_Node *temp;
//     if (root == NULL)
//         return root;
//     if (id < root->client->id)
//         root->left = deleteClient(root->left, id);
//     else if (id > root->client->id)
//         root->right = deleteClient(root->right, id);
//     else
//     {
//         if (root->left == NULL)
//         {
//             temp = root->right;
//             free(root->client);
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//             temp = root->left;
//             free(root->client);
//             free(root);
//             return temp;
//         }
//         temp = minValueNode(root->right);
//         root->client->id = temp->client->id;
//         root->right = deleteClient(root->right, temp->client->id);
//     }
//     return root;
// }




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
