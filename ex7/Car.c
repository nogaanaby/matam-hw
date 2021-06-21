#include "Car.h"


Tree *createCarsTree()
{
    return createTree();    
}


int addCarToTree(Tree *tree)
{
    return addNewNode(tree,createCar,compere_tow_cars);
}

/* compere tow cars  if nodes  are  null print error  massge  and  return 
if not  compere tow nodes return 0 if equal */
unsigned int compere_tow_cars(Node* car1,Node* car2){
    /* create  temp car for comparision  */
    Car *temp1 = car1->value ,*temp2 = car2->value;
    if(car1 && car2){
        return -2; 
    }else {  
        if(temp1->license_id < temp2->license_id){
            return 1 ; 
        }else if(temp1->license_id > temp2->license_id){
            return -1;
        }else{
            return 0 ; 
        } 
    }

}


/* if left sub trre is biger  then rihgt  sub tree then go rihgt  else  go left  
this will keep trre leveld  */
void createCar(Node *new_node)
{
    Car *new_car = (Car*) malloc(sizeof(Car));
    if(new_car && new_node){
        get_input_from_user(new_car);
        new_node->value = (Car*) new_car;
    }
}

void get_input_from_user(struct Car *temp_car)
{
    get_int_input("Please enter (7 digit) license id number:\t", &temp_car->license_id, MAX_LEN_SEVEN);
    get_int_input("Please enter (5 digit) frame id number:\t", &temp_car->frame_id, MAX_LEN_FIVE);
    get_int_input("Please enter (4 digit) year of relase:\t", &temp_car->year_of_relase, MAX_LEN_FOUR);
    get_chr_input("Please enter (10 digit) manufacturer name:\t", temp_car->manufacturer_name, ALLOC);
    get_chr_input("Please enter (10 digit) model name:\t", temp_car->model_name, ALLOC);
    get_chr_input("Please enter (7 digit) color of car:\t", temp_car->color, ALLOC);
    get_int_input("Please enter (4 digit) road raising year:\t", &temp_car->road_raising_year, MAX_LEN_FOUR);
    get_int_input("Please enter (7 digit) supplier price:\t", &temp_car->supplier_price, MAX_LEN_SEVEN);
    get_int_input("Please enter (7 digit) current price:\t", &temp_car->current_price, MAX_LEN_SEVEN);
    get_int_input("Please enter (4 digit) engine_capacity:\t", &temp_car->engine_capacity, MAX_LEN_FOUR);
    printf("\n");
}

Node* FindCarInTreeByid(Tree *tree, int id)
{   
    Node *cuurent  =  tree->root; 
    Car *car  = cuurent->value;    
    while(cuurent == NULL)
    {
       car = cuurent->value; 
       if(car->license_id == id){
           return cuurent ; 
       }else if(car->license_id > id){
           cuurent = cuurent->left ; 
       }else{
           cuurent = cuurent->right; 
       }
    }
    printf("car is not found\n");
    return NULL ; 
}


/* return the number of car with given capacity  */
int carNumberWithGivenCapacity_REC(Node *head, int engine_val)
{
    Car *temp_car; 
    int sum = 0;
    if (head == NULL)
    {
        return 0;
    }
    temp_car = head->value ; 
    if (temp_car->engine_capacity == engine_val)
    {
        sum++;
    }
    /* sum of sub left tree */
    sum += carNumberWithGivenCapacity_REC(head->left, engine_val);
    /* sum of sub right tree */
    sum += carNumberWithGivenCapacity_REC(head->right, engine_val);
    return sum;
}

/* print car list */

void printCarTree(Tree *tree)
{
    printtree_rec(tree->root,0,print_car);
}


void print_car(Node *node,int count){
    Car *car;
    if(node->value)
    {
        car = node->value;
        printf("\tcolor:\t%s\n",car->color);
        printf("\tprice:\t%d\n",car->current_price);
        printf("\tengine capcity\t%d\n",car->engine_capacity);
        printf("\tfreme number:\t%d\n",car->frame_id);
        printf("\tlicense number:\t%d\n",car->license_id);
        printf("\tmanufacturer name:\t%s\n",car->manufacturer_name);
        printf("\tmodel name:\t%s\n",car->model_name);
        printf("\troad rising year :\t%d\n",car->road_raising_year);
        printf("\tsupplier_price:\t%d\n",car->supplier_price);
        printf("\tyear of relase:\t%d\n\n",car->year_of_relase);
    }
    printf("fail to print\n");
}
/* remove  a  single  car from tree 
on succsees return 0  else  retrun -1   */ 
int removeCarFromTree(Tree *tree,int id){
    Node *res  = FindCarInTreeByid(tree,id);
    Car* temp ; 
    int remove = 0 ; 
    /* if found  remove  from tree */
    if(res){
        temp = res->value ; 
        free(temp->color);
        free(temp->manufacturer_name);
        free(temp->model_name);
        remove = removeNode(tree,tree->root,res,compere_tow_cars);
        if(!remove){return 0;  } 
    }
    printf("Error item is not in the tree, canot  remove from tree ! \n");
    return -1; 
}


/* free all alloceted field */
 void free_car(Node *tmp)
{
    Car* car = tmp->value; 
    free(car->manufacturer_name);
    free(car->model_name);
    free(car->color);
}




/* destroy car list   */
void destroyCarTree(Tree *tree)
{
    if (tree)
    {
        freeTree(tree->root,free_car);
        tree->root = NULL ;
    }
}
