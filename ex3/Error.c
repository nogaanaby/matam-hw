
#include "Error.h"


int validateInput(char* data,unsigned int size){
    if( length(data) != size ){
        /*check size error*/
        printf("cahr vaule error:\t\n");
        printError(size_);
        return -1;
    }
    int i = 0 ; 
    for(i < size ; i++){
        /*check type error*/
        if(!(isalpha(data[i]))){
            printError(type_);
            return -1;
        }
    }

    return 0 ; 
}

int validateInputInt(int data,unsigned int size){
    if(data < 0 ){
        printError(negitive_);
        return -1;  
    }else if(!isdigit(data)){
         printError(type_);
         return -1;
    }else{
        int i = 0 ; 
        char temp_buf[TEN+1]
        /*convert int to char array seve into temp_buf*/
        sprintf(temp_buf,"%d",data);
        if(length(buf) != size){
            printf("intger vaule error:\t\n");
            printError(size_);
            return -1;
        }
    }
    return 0 ; 
}


void printError(int errorCode){
    switch(errorCode){
        
        case size_:
            printf("Error size of input is incorrect \n");
            break;
        
        case negitive_:
            printf("Error from type int input is negitive \n");
            break;
        
        case type_:    
            printf("Error type of input is incorrect \n");
            break;
        
    }
}

