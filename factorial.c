#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int factorial(int num) ;


int main(){
    printf("%s","hello world \n");
    factorial(0);
    factorial(2);
    factorial(3);
    factorial(4);
    factorial(5);
    factorial(6);
    factorial(7);
    factorial(10);
    factorial(15);
    factorial(20);
    return 0 ;
}


int factorial(int num){
    long int  res = 1 ; 
    if(!(isdigit)){printf("%s","error in input");exit(1);}
    for(int i = 1 ; i <= num ; i++){
        res += res * i;
    }
    printf("%d\n ,",res);
}