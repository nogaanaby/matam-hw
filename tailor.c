#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define INF 5 

unsigned long long factorial(double num);
double taylor(double angle);
double convert_to_rad(float angle);


int main(){
     taylor(90);
     taylor(120);
     taylor(360);
    return 0; 
}


double convert_to_rad(float degree){
    double pi = 3.14159265359;
    printf("this is x : %u , \n",(degree * (pi / 180)));
    return (degree * (pi / 180));
}

unsigned long long factorial(double num){
    if(num < 0 ){"%s","error  factorial of a nagtive number \n";exit(1);}
    unsigned long long  res = 1 ; 
    for(int i = 1 ; i <= num ; i++){
        res *= i;
    }
    return res;
}


double taylor(double angle){
    double X = convert_to_rad(angle);
    double sin = 0.0 ;  
    for(int i = 0 ; i < INF ; i++){        
        sin  += ((i%2 ? 1 : -1) / factorial(2*i+1)) * pow(X,2*i+1);
        printf(" this is the resualt : %f , \n",sin);
    }
    printf(" this is the final resualt! : %f , \n",sin);
    return sin ; 
}
