// qu 2 contine  part 1 and part2
#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
// part 1
int removeMaxDigit(int num );
// part 2
int maxdigit(); 

int main(){
    // part2
    int res = removeMaxDigit(34598); 
    // return val res = 3458 
    printf("this is final number : %d  , \n",res);
    res = removeMaxDigit(384); 
    printf("this is final number : %d  , \n",res);
    res = removeMaxDigit(96853); 
    printf("this is final number : %d  , \n",res);
    // part1
    int maxDigit = maxdigit(34598);
    printf("this is max digit : %d  , \n",maxDigit);
    maxDigit = maxdigit(6854723);
    printf("this is max digit : %d  , \n",maxDigit);
    maxDigit = maxdigit(3);
    printf("this is max digit : %d  , \n",maxDigit);
    maxDigit = maxdigit(-10);
    printf("this is max digit : %d  , \n",maxDigit);
    return 0 ; 
}


int maxdigit(int num ){
    int max_dig = 0,temp_dig = 0 ;
    if ( num < 0 ){printf("%s : %d \n","error nagtive Intger",num);exit(1);} 
    while(num != 0 ){
        temp_dig = num % 10 ;
        printf("temp  : %d  , \n",temp_dig);
        num /= 10 ; 
        if(temp_dig  > max_dig){max_dig = temp_dig ;}
    }
    return max_dig;
}

int removeMaxDigit(int num ){
    int max_dig = maxdigit(num),size = 0,temp_num = num ;
    if ( num < 0 ){printf("%s : %d \n","error nagtive Intger",num);exit(1);} 
    while(temp_num != 0 ){
        size++; 
        temp_num /= 10 ; 
    }
    printf("this is size  : %d\n",size);
    int  arr_num[size]; 
    for(int i = 0 ; i < size && num != 0 ; i++){
        if(max_dig != num % 10)
        arr_num[i] = num % 10 ;
        num /= 10 ;  
    }
    int final_num = 0 ; 
    for(int index = size-1;  0 < size ;index-- ,size-- ){
        if(arr_num[index] != 0 )
        final_num += arr_num[index]*pow(10,size);
    }

    return final_num;
}

