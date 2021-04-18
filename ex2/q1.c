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


void ReorderArray(char **arr,int size){
    char tmp[5];
    int currentIndex=0, tmpIndex=0;

    int *ptr1=*arr+1;
    for(;*arr<=*arr+size;*arr++){
        if(isLetter(**arr)) {
            tmp[tmpIndex]=**arr;
            tmpIndex++;
        }
    }
    for(;*arr<=*arr+size;*arr++){
        if(isDigit(**arr)) {
            tmp[tmpIndex]=**arr;
            tmpIndex++;
        }
    }
    for(;*arr<=*arr+size;*arr++){
        if(!isDigit(**arr)&&!isLetter(**arr)) {
            tmp[tmpIndex]=**arr;
            tmpIndex++;
        }
    }
    char *ptr=tmp;
    *arr=ptr;
}


int main(){
    char *arr = "k8#i^";
    ReorderArray(&arr,5);
    printf("*arr %s", arr);
}