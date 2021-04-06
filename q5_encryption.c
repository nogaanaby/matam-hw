#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <setjmp.h>
#include <string.h>

jmp_buf savebuf; /* tool for exception handeling in C */
int exception_value=0;
#define TRY if((exception_value=setjmp(savebuf))==0)
#define CATCH(NUM) else if (exception_value==NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf,NUM)


char encrypt(char cap, unsigned int k){
    int newCapVal,newSmallVal;
    if((int)cap<65 || (int)cap>90){
       THROW(1); /* call the exception if the user didnt input a capital letter */
    }
    /* if the given k number is larger then 26 -> I care only about the reminder of 26 to remain it cicular */
    k=k%26;
    
    if((int)cap + k>90){ /* circular */
        k=k-(90-(int)cap);
        newCapVal=64 + k;
    }else{
        newCapVal=(int)cap + k;
    }
 
    newSmallVal=newCapVal+32;
    return (char)newSmallVal;
}

char decrypt(char sm, unsigned int k){
    int oldSmVal,oldCaplVal,rem;
    if((int)sm<97 || (int)sm>122){
       THROW(3);
    }

    k=k%26;
    
    if((int)sm - k < 97){ /* circular */
        rem=k-(int)sm+97;
        oldSmVal=123-rem;
    }else{
        oldSmVal=(int)sm - k;
    }
 
    oldCaplVal=oldSmVal-32;
    return (char)oldCaplVal;
}

void tester(){
    TRY { 
        printf("should be c: %c \n", encrypt('A', 2));
        printf("should be a: %c \n", encrypt('X', 3));
        printf("should be error negative: %c \n", encrypt('X', -3));
        printf("should be error negative: %c \n", encrypt('X', 3.7));
        printf("should be b: %c \n", encrypt('V', 32));
        printf("should be error: %c \n", encrypt('a', 32));
    }
    CATCH(2) {
        printf("ERROR! your text might not contain only small letters \n");
    }  CATCH(1) {
        printf("ERROR! your text might not contain only capital letters \n");
    } 
    CATCHALL { 
        printf("ERROR! invalid input \n");
    }
}

int main(){
    int k;
    char original[255];
    tester();

    printf("Please type an encryption key (make sure it is positive and integer): ");
    scanf("%d", &k);
    printf("Please type your encryption text in capital letters: ");
    scanf("%s", original);

    printf("Your encrypted text is: \n");
    for(int i=0; i<strlen(original);i++){
        TRY { 
           printf("%c", encrypt(original[i], k));
        }
        CATCH(2) {
            printf("ERROR! your text might not contain only small letters \n");
            return 0;
        }  
        CATCH(1) {
            printf("ERROR! your text might not contain only capital letters \n");
            return 0;
        } 
        CATCHALL { 
            printf("ERROR! invalid input \n");
            return 0;
        }
    }
    return 1;
}