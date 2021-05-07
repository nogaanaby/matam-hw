
#include "car.h"
#include "Error.h"

// create array of cars fix size N, set the fildes to zero 
int createCarList(struct Car* car){
// to Do
    //check if the(car has the correct types and size
        if(car == NULL ){printf("error list is empty\n");return -1;}
        for(int i = 0 ; i <  N ; i++){
            /* init the string with zero*/
            strcpy((car+i)->color,"");
            (car+i)->current_price =0;
            (car+i)->engine_capacity =0;
            strcpy((car+i)->frame_id,"");
            strcpy((car+i)->license_id,"");
            strcpy((car+i)->manufacturer_name,"");
            strcpy((car+i)->model_name,"");
            (car+i)->road_raising_year = 0;
            (car+i)->supplier_price = 0;
            (car+i)->year_of_relase = 0;
            (car+i)->is_empty = 0 ;             
        }
    return 0;
}

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
struct Car addNewCar(){
// to Do 
    Car temp_car =  get_input_from_user();
    print_car(&temp_car);
    /* chenge is_empty to false*/
    /*splite into 3 function 1. get_input 2. check input 3. 
    return car and put into array in index  */
    return temp_car;
}

struct Car get_input_from_user(){
    char *license_id,*frame_id,*manufacturer_name,*model_name,*color;
    int supplier_price,current_price,engine_capacity,year_of_relase,road_raising_year;
    Car* temp_car ;
    printf("Please enter (7 digit) license id number:\t\n");
    scanf("%s",license_id);
    if(validateInput(license_id,MAX_LEN_SEVEN) == 0 )
        strcpy((temp_car)->license_id,license_id);
    printf("Please enter (5 digit) frame id number:\t\n");
    scanf("%s",frame_id);
    if(validateInput(frame_id,MAX_LEN_SEVEN) == 0 )
        strcpy((temp_car)->frame_id,frame_id);
    printf("Please enter (10 digit) manufacturer name:\t\n");
    scanf("%s",manufacturer_name);
    if(validateInput(manufacturer_name,MAX_LEN_TEN) == 0 )
        strcpy((temp_car)->manufacturer_name,manufacturer_name);
    printf("Please enter (10 digit) model name:\t\n");
    scanf("%s",model_name);
    if(validateInput(model_name,MAX_LEN_TEN) == 0)
        strcpy((temp_car)->model_name,model_name);
    printf("Please enter (7 digit) color of car:\t\n");
    scanf("%s",color);
    if(validateInput(color,MAX_LEN_SEVEN) == 0 )
        strcpy((temp_car)->color,color);
    printf("Please enter (4 digit) year of relase:\t\n");
    scanf("%d",&year_of_relase);
    if(validateInputInt(year_of_relase,MAX_LEN_FOUR) == 0)
        (temp_car)->year_of_relase = year_of_relase;
    printf("Please enter (4 digit) road raising year:\t\n");
    scanf("%d",&road_raising_year);
    if(validateInputInt(road_raising_year,MAX_LEN_FOUR) == 0)
        (temp_car)->road_raising_year = road_raising_year;
    printf("Please enter (7 digit) supplier price:\t\n");
    scanf("%d",&supplier_price);
    if(validateInputInt(supplier_price,MAX_LEN_SEVEN) == 0)
        (temp_car)->supplier_price = supplier_price;        
    printf("Please enter (7 digit) current price:\t\n");
    scanf("%d",&current_price);
    if(validateInputInt(current_price,MAX_LEN_SEVEN) == 0)
        (temp_car)->current_price = current_price;       
    printf("Please enter (4 digit) engine_capacity:\t\n");
    scanf("%d",&engine_capacity);
    if(validateInputInt(engine_capacity,MAX_LEN_SEVEN) == 0)
        (temp_car)->engine_capacity = engine_capacity;
    (temp_car)->is_empty = 1 ;

    return *temp_car; 
}
    

// int addCarToArray(struct Car car){

// }

// sarch for cars in data base 
struct Car* searchBy_license_id( struct Car* car, char* value){
// to Do
    if(car == NULL ){printf("error list is empty\n");return NULL;}
    for(int i = 0 ; i < N ; i++){
        if((car+i)->is_empty == 1){ return NULL;}
        if( strcmp((car+i)->license_id,value) == 0 ){
            return (car+i);
        }
    }
    return NULL;
}

struct Car* searchBy_engine_capacity( struct Car* car, char* value){
    if(car == NULL ){printf("error list is empty\n");return NULL;}
        for(int i =0 ; i < N ; i++){
            if(!((car+i)->is_empty)){
                if( (car+i)->engine_capacity == value ){
                    return (car+i);
                }
            }
    }
    return NULL;
}


void print_car(struct Car* car){
            if(car->is_empty){
                printf("car is empty\n");
            }else {
            /* init the string with zero*/
                printf("color:\t%s\n",(car)->color);
                printf("price:\t%d\n",(car)->current_price);
                printf("engine capcity\t%d\n",(car)->engine_capacity);
                printf("freme number:\t%s\n",(car)->frame_id);
                printf("license number:\t%s\n",(car)->license_id);
                printf("manufacturer name:\t%s\n",(car)->manufacturer_name);
                printf("model name:\t%s\n",(car)->model_name);
                printf("price:\t%d\n",(car)->road_raising_year);
                printf("supplier_price:\t%d\n",(car)->supplier_price);
                printf("year of relase:\t%d\n\n",(car)->year_of_relase);
            }  
}

void print_car_list(struct Car* car){
    for(int i = 0 ; i <  N ; i++){
        printf("index in array:\t%d\n",i);
        print_car(car+i);
    }     
}

// delte car cy id number
int deleteCar(struct Car* car,char* license_id){
    // do we need to move all the valus of array backword  ?
    struct Car* res = searchBy_license_id(car,license_id);
    if(res != NULL ){
        deleteSingleCar(res);
        return 0 ;
    }
    return -1 ; 
}

// delete all cars 
int deleteAllCars(struct Car* car){
    if(car == NULL ){printf("list is empty\n");return -1;}
    for(int i = 0 ; i < N && (car+i) != NULL ; i++){
        deleteSingleCar(car+i); 
    }
    car = NULL ; 
    return 0 ; 
}

void deleteSingleCar(struct Car* car){
        strcpy((car)->color,"");
        (car)->current_price = 0;
        (car)->engine_capacity = 0;
        strcpy((car)->frame_id,"");
        strcpy((car)->license_id,"");
        strcpy((car)->manufacturer_name,"");
        strcpy((car)->model_name,"");
        (car)->road_raising_year = 0;
        (car)->supplier_price = 0;
        (car)->year_of_relase = 0;
        (car)->is_empty = 1;
} 