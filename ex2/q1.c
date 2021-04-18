#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <setjmp.h>
#include <string.h>

bool isLetter(char c){
    int n=(int)c;
    if((n>64 && n<91) || (n>96 && n<123)){ //curent char is a letter
        return true;
    }
    return false;
}

bool isDigit(char c){
    int n=(int)c;
    if(n>47 && n<58){ 
        return true;
    }
    return false;
}

// void swap(char *adr1, char *adr2){
//     char temp=adr1;
//     //char temp2=*adr2;
//     //*adr1="d";//error
//     //*adr1='d';//error
//     adr1=adr2;//error
//     adr2=temp;
// }
void stringSwap(char** a, char** b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// void ReorderArray(char *arr,int size){
//     char *currentCell=&(*arr[0]), *letterCell=&(*arr[0]);
    
//     //*utilsCell=&(*arr[size-1]);
//     //char *afterLastCell=&(*arr[size]);

//     printf(" currentCell %s \n", currentCell); //"k8g$3%e9oo"
//     printf(" *currentCell %c \n", *currentCell);// k
//     printf(" &currentCell %x \n", &currentCell);//fffcbe0
//     printf(" &*currentCell %x \n", &*currentCell);//403056

//     //printf(" utilsCell %s \n", utilsCell);
//     //printf(" arr %c \n", *arr);
//    // printf(" &utilsCell %x \n", &utilsCell);

//     for(;&*currentCell<&currentCell;currentCell++){

//         if(isLetter(*currentCell) && currentCell>letterCell) {// if its a letter
//             swap(currentCell,letterCell); // move it to the begining
//             letterCell++;
//         }else if (!isDigit(*currentCell)){
//             swap(currentCell,utilsCell); //sawp it to the end
//             utilsCell--;
//         }
//     }
// }

void ReorderArray(char *arr,int size){

    char *currentCell=arr;
    char *utilsCell=arr+size-1;
    char *letterCell=arr;

    char copystr[250];
    strcpy(copystr, arr);

    int currentIndex=0, utilsIdex=size-1,letterIndex=0;

    for(;currentCell<=utilsCell;currentCell++){

        if(isLetter(*currentCell) && currentCell>letterCell) {// if its a letter
            stringSwap(&currentCell,&letterCell);// move it to the begining
            *(arr+currentIndex)=*currentCell;
            *(arr+letterIndex)=*letterCell;
            letterCell++;letterIndex++;
        }else if (!isLetter(*currentCell) && !isDigit(*currentCell)){
            //swap(currentCell,utilsCell); //sawp it to the end
            utilsCell--;
        }
        currentIndex++;
    }
    char *blaa="kjogg9090";
    arr=blaa;
}


int main(){
    char *arr = "k8g$3%e9oo";
    //kgeoo839$%
    printf("*arr = %s \n", arr );
    ReorderArray(arr,10);
    printf("*arr = %s \n", arr );
}