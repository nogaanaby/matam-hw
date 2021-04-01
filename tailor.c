#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846264338327

#define INF 10

unsigned long long factorial(double num);
double taylor(double angle);
double convert_to_rad(float angle);


int main(){
     taylor(M_PI);
     taylor(1.5 * M_PI);
     taylor(0.5 * M_PI);
    return 0; 
}



unsigned long long factorial(double num){
    if(num < 0 ){printf("error factorial of a nagtive number \n");exit(1);}
    unsigned long long  res = 1 ; 
    for(int i = 1 ; i <= num ; i++){
        res *= i;
    }
    return res;
}


double taylor(double angle){
    double X = angle;
    double sin = 0.0 ;  
    for(int i = 0 ; i < INF ; i++){        
        sin  += ((i%2 ? -1 : 1)* pow(X,(2*i+1))) / (factorial(2*i+1));
        printf(" i = %d  , result = %f , \n",i,sin);
    }
    printf(" sin(x) =  %f , \n",sin);
    return sin ; 
}
