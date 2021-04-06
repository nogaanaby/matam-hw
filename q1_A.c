#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
unsigned long long factorial(double num);
    
int main(){
    factorial(0);
    factorial(2);
    factorial(3);
    factorial(4);
    factorial(5);
    factorial(6);
    factorial(7);
    factorial(10);
    factorial(11);
    factorial(12);
    factorial(13);
    factorial(14);
    return 0 ;
}


unsigned long long factorial(double num){
    if(num < 0 ){"%s","error  factorial of a nagtive number \n";exit(1);}
    unsigned long long  res = 1 ; 
    for(int i = 1 ; i <= num ; i++){
        res *= i;
    }
    printf("this is the final resualt : %lu , \n",res);
    return res;
}
