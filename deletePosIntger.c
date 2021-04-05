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
void printDigits(long number);

int main(){
    printf("delReverse(1234454647448494, 4)= %d \n", delReverse(1234454647448494, 4));
    //printf("printDigits(77724457)= %d \n", printDigits(77724457));
    printDigits(2727724557);

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
    printf("resualt is  : %d , \n",count);
    return count; 
}

int maxOccurs(long number){
    long temp_num = number , maxOccurs = 0 , dig = 0 ;
    int arr[SIZE] = { 0 };
    while( temp_num != 0){
        printf("%ld , \n",temp_num % 10); 
        arr[(temp_num % 10)]++; 
        temp_num /= 10;
    }
    maxOccurs = *arr ; 
    for(int i = 1 ; i < SIZE ; i++){
        if(maxOccurs < arr[i] ){maxOccurs = arr[i] ; dig = i ; }
        else if( dig < i && arr[i] == maxOccurs){dig = i ;}
    }
    printf("resualt is  : %ld , \n",dig);
    return  dig; 
}




long delReverse (long number, int digit){
    long long bucket = number;
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
    //sorts the number (exc 2727724557) into two arrays:
    int cur=number%10;
    long bucket=number/10;

    //the singles brings every digit once, exc: [7,5,4,2]
    int singles[20];
    singles[0]=cur;

    //the countHowMeny- counts how many digits do I have - Respectively to the indexes in the "singles" array, exc: [4,2,1,3]
    int countHowMeny[20];
    countHowMeny[0]=1;
    int countHowMeny_length=1;

    int types=1;
    int i=1;
    bool curBeenBefore;

    while(bucket!=0){
        curBeenBefore=false;
        cur=bucket%10;
        bucket /=10;
        
        for(int j=0;j<countHowMeny_length;j++){ //singles[7,5,4,2]
            if (singles[j]==cur){
                countHowMeny[j]++;
                curBeenBefore=true;
                break;
            }
        }
        if(!curBeenBefore){//prev!=cur and cur has never been before
            singles[types]=cur; 
            countHowMeny[types]=1;
            types++;
            countHowMeny_len  gth++;
        }
        i++;
    }


    printf("singles: [ ");
    for(int x=0;x<countHowMeny_length ;x++){
        printf("%d, ", singles[x]);
    }
    printf("] \n");


    printf("countHowMeny: [ ");
    for(int x=0;x<countHowMeny_length ;x++){
        printf("%d, ", countHowMeny[x]);
    }
    printf("] \n");


    //now it sorts singles (exc [7,5,4,2]) by the size of coundHowMany (exc [4,2,1,3])
}
