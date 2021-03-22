#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define INF 10 
#define PIE 3.14159 

int factorial(int num);
double taylor(double angle);
double convert_to_rad(double angle);


int main(){
     taylor(60);
     taylor(120);
     taylor(240);
    return 0; 
}


double convert_to_rad(double angle){
     double res = (angle *  (PIE / 180.0)) ;
     return res;
}

int factorial(int num){
    long int  res = 1 ; 
    for(int i = 1 ; i <= num ; i++){
        res += res*i;
    }
}


double taylor(double angle){
    double X = 4.18;
    double sin = 0.0 ;
    float num_i = 0.0 ;  
    for(int i = 0 ; i < INF ; i++){
        num_i = i%2?1:-1;
        printf(" this is num_i :%u",num_i);  
        sin  = sin + ((num_i / factorial(2*i+1)) * pow(X,2*i+i));
    }
    return sin ; 
}
