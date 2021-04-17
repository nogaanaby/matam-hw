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

void ReorderArray(char* arr[],int size){
    char tempArr[size];
    int x=0,y=size-1;
    for(int i=0;i<size;i++){
        if((arr[i]>64 && arr[i]<91) || (arr[i]>96 && arr[i]<123)){ //curent char is a letter
            tempArr[x]=arr[i];
            x++;
        }
        else if(arr[i]<48 || arr[i]>57){ //not a number -> its a str%$#@
            tempArr[y]=arr[i];
            y--;
        }
    }
    arr*=&tempArr;
}

int main(){
    char arr[]= "k8g$3%e9oo";
    ReorderArray(arr,10);
}