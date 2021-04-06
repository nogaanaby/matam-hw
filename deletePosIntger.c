#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 10 

/* part 1 */
int numOccurs(int digit , long number );
/* part 2 */
int  maxOccurs(long number);
/* part 3 */
long delReverse(long number, int digit);
/* part 4 */
void printDigits(long number);

int main(){
    
    printDigits(77275513);
    printDigits(0);

    numOccurs(3,31573);
    numOccurs(8,31573); 
    numOccurs(1,31573);
    numOccurs(9,3157452368);
    maxOccurs(34573);
    maxOccurs(35777);
    maxOccurs(7987878);
    maxOccurs(26539548364);
    maxOccurs(1122);
    return 0;
}

int numOccurs(int digit,long number){
    int count = 0; 
    while(number != 0 ){
        if(digit == number%10){
            count++;
        }
        number /= 10 ; 
    } 
    /* printf("resualt is  : %d , \n",count); */
    return count; 
}

int maxOccurs(long number){
    long temp_num = number , maxOccurs = 0 , dig = 0 ;
    int arr[SIZE] = { 0 };
    while( temp_num != 0){
        /* printf("%ld , \n",temp_num % 10); */
        arr[(temp_num % 10)]++; 
        temp_num /= 10;
    }
    maxOccurs = *arr ; 
    for(int i = 1 ; i < SIZE ; i++){
        if(maxOccurs < arr[i] ){maxOccurs = arr[i] ; dig = i ; }
        else if( dig < i && arr[i] == maxOccurs){dig = i ;}
    }
    /* printf("resualt is: %d, \n",dig); */
    return  dig; 
}


long delReverse (long number, int digit){
    long bucket = number;
    int curDig,reversedNum=0;
    while(bucket!=0){
        curDig=bucket%10;
        bucket/=10;
        if(curDig!=digit){
            reversedNum=curDig+reversedNum*10;
        }
    }
    return reversedNum;
}


void printDigits(long number){
    long bucket=number;
    int dig;
    printf("the digits are: ");
    if(bucket==0){
        printf("0");
    }else{
        while(bucket!=0){
            dig = maxOccurs(bucket);
            printf("%d ", dig);
            bucket=delReverse(bucket, dig);
        }
    }
    printf("\n ");
}

