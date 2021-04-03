#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPythagorean(unsigned int num1, unsigned int num2){
  double x = pow((double)num1,2)+pow((double)num2,2);
  x=sqrt(x);
  if(floorf(x)==x){
      return true;
  }
  return false;
}

void printPythagoreanTriples(){
    for(int i=1;i<100;i++){
        int j=i;
        while( pow(i,2)+pow(j,2)<=pow(99,2) ){
            if(isPythagorean(i,j)){
                printf("%d^2 + %d^2 = %d^2 \n",i,j,(int)sqrt(pow((double)i,2)+pow((double)j,2)));
            }
            j++;
        }    
    }
}
 
void main(){
    printPythagoreanTriples();
}