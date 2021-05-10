
#include "Utils.h"
#include <string.h>

//theres a problem here -> some of the fields has a maximum size that smaller one does much as well
int validateInput(char* data,unsigned int size,int fixedSize){
    if(fixedSize==1 && strlen(data) != size ){
        /*check size error*/
        printf("char value error:\t\n");
        printError(size_);
        return -1;
    }else if(strlen(data) > size){
        printf("char value error, too long:\t\n");
        printError(size_);
        return -1;
    }
    int i;
    for(i = 0;i < strlen(data); i++){
        /*check type error*/
        if(!(isalpha(data[i])) && !(isdigit(data[i])) && !(isspace(data[i])) ){
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
        char temp_buf[TEN+1];
        /*convert int to char array seve into temp_buf*/
        sprintf(temp_buf,"%d",data);
        if(strlen(temp_buf) != size){
            printf("intger value error:\t\n");
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

int get_chr_input(char text[],char *attr,int attr_size ){
    printf("%s:\t\n",text);
    scanf("%s",attr);
    if(validateInput(attr,attr_size,0) == 0 ){
        return 0;
    }else{
        return -1;
    }
}

//this function thows an error
int get_int_input(char text[],int *attr,int attr_size ){
    printf("%s:\t\n",text);
    int input;
    //Im not sure if it scans the value properly
    scanf("%d",*attr);
    //*attr=input;
    printf("attr = %d:\t\n",*attr);
    if(validateInputInt(*attr,attr_size) == 0 ){
        printf("ok:\t\n");
        return 0;
    }
    else
        return -1;    
}
