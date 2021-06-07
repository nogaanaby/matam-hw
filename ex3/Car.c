#include "Car.h"



BinarySearchTree* createCarTree(){   
    BinarySearchTree *new_tree = (BinarySearchTree*) malloc(sizeof(BinarySearchTree));
    if(new_tree){
        new_tree->root = NULL; 
        new_tree->elementCount = 0 ; 
        return new_tree;
    }
    /* allocetion field exit prog */
    printError(NULL_);
    return NULL;
}

/* remove from file only test */
 void get_car_test(struct Car* car){
    static int i  = 1 ; 
    car->frame_id = (12345+i) ; 
    car->license_id = (1234567+i) ;
    if(i==1 || i == 3){car->year_of_relase = 2012-(i*10);}
    else{car->year_of_relase = 2012+i;} 
    car->manufacturer_name = my_strdup("nisan") ; 
    car->model_name = my_strdup("micra") ; 
    car->color = my_strdup("red");
    car->road_raising_year = 1992+i ; 
    car->supplier_price = 20000000+i; 
    car->current_price =  20000000+i;
    if(i==1 || i == 3){car->engine_capacity = 2000-(i*10);}
    else{car->engine_capacity = 2000;} 
    i++;
}
/* remove from file only test */

void addCarToTree(Node* head){
     Node* new_node_Tree = (Node*) malloc(sizeof(Node));
     new_node_Tree->car = ( Car*) malloc(sizeof( Car));
     new_node_Tree->left = NULL ;
     new_node_Tree->right = NULL ;
     new_node_Tree->sum_of_sub_tree_left = 0 ;
     new_node_Tree->sum_of_sub_tree_right = 0 ;  
     if(new_node_Tree){
         /* init node with perms of car */
            get_car_test(new_node_Tree->car);
            /*get_input_from_user(new_node_Tree->car); */         
            insertNodeToTree(head,new_node_Tree);
     }
}


/* if left sub trre is biger  then rihgt  sub tree then go rihgt  else  go left  
this will keep trre leveld  */
void insertNodeToTree( Node *root, Node* new_node){
            if(new_node){
                if(root == NULL ){
                    root = new_node;
                    return;
                }
                /* go right */
                if(root->sum_of_sub_tree_left > root->sum_of_sub_tree_right){
                    insertNodeToTree(root->right,new_node);
                    root->sum_of_sub_tree_right++;
                }
                /* go left */
                insertNodeToTree(root->left,new_node);
                root->sum_of_sub_tree_left++; 
            }
}



void get_input_from_user(struct Car* temp_car){
    get_int_input("Please enter (7 digit) license id number:\t",&temp_car->license_id,MAX_LEN_SEVEN);
    get_int_input("Please enter (5 digit) frame id number:\t",&temp_car->frame_id,MAX_LEN_FIVE);
    get_int_input("Please enter (4 digit) year of relase:\t",&temp_car->year_of_relase,MAX_LEN_FOUR);
    get_chr_input("Please enter (10 digit) manufacturer name:\t",temp_car->manufacturer_name,ALLOC);
    get_chr_input("Please enter (10 digit) model name:\t",temp_car->model_name,ALLOC);
    get_chr_input("Please enter (7 digit) color of car:\t",temp_car->color,ALLOC);
    get_int_input("Please enter (4 digit) road raising year:\t",&temp_car-> road_raising_year,MAX_LEN_FOUR);
    get_int_input("Please enter (7 digit) supplier price:\t",&temp_car-> supplier_price,MAX_LEN_SEVEN);
    get_int_input("Please enter (7 digit) current price:\t",&temp_car-> current_price,MAX_LEN_SEVEN);
    get_int_input("Please enter (4 digit) engine_capacity:\t",&temp_car-> engine_capacity,MAX_LEN_FOUR);
}

struct Node* FindCarInTreeByid(Node* head,int id){
    Node *res = NULL;
    if( head==NULL ){
        return NULL  ; 
    } 

    if(head->car->license_id == id ){
        res =  head ;
    } 

    /*start with the root  if it`s not me go left and then go right*/
    res = FindCarInTreeByid(head->left,id);
    res = FindCarInTreeByid(head->right,id);
    return res ; 
}

void printCarTree(Node* head){
     if(head == NULL){
         return; 
     }  
     printCarTree(head->left);
     printCarTree(head->right);
     print_car(head->car);
}



/* free all alloceted field */
void free_car(Node* tmp){
        free(tmp->car->manufacturer_name);
        free(tmp->car->model_name);
        free(tmp->car->color);
        free(tmp);
}

/* return the number of car with given capacity  */
int carNumberWithGivenCapacity_REC(Node *head,int engine_val){
    int sum = 0 ; 
    if(head == NULL){return 0 ; }
    if(head->car->engine_capacity == engine_val){sum++;}
    sum += carNumberWithGivenCapacity_REC(head->left,engine_val);
    sum += carNumberWithGivenCapacity_REC(head->right,engine_val);
    return sum ; 
}

/* 
int removeCarFromList(Node** head,int id){
    to do 
}
 */

void print_car(struct Car* car){
                if(car){
                    printf("\tcolor:\t%s\n",(car)->color);
                    printf("\tprice:\t%d\n",(car)->current_price);
                    printf("\tengine capcity\t%d\n",(car)->engine_capacity);
                    printf("\tfreme number:\t%d\n",(car)->frame_id);
                    printf("\tlicense number:\t%d\n",(car)->license_id);
                    printf("\tmanufacturer name:\t%s\n",(car)->manufacturer_name);
                    printf("\tmodel name:\t%s\n",(car)->model_name);
                    printf("\troad rising year :\t%d\n",(car)->road_raising_year);
                    printf("\tsupplier_price:\t%d\n",(car)->supplier_price);
                    printf("\tyear of relase:\t%d\n\n",(car)->year_of_relase);
                }
                
}

void destroyCarTree(BinarySearchTree* tree){
    destroyTree(tree->root);
    /* delete the tee struct  */
    free(tree);
}

void destroyTree(Node* temp){
     if (temp == NULL){
        return ; 
    }
    destroyTree(temp->left);
    destroyTree(temp->right);
    free_car(temp);
}
