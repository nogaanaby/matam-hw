 #include<stdio.h>
#include<ctype.h>
#include <string.h>


/* part 01
 the function dont get the right index */
void reverseArray(char * str , unsigned int length_str);
/* part 02
 the function desnot get the proper value of char */
void insertLength(char str[],char var,int start);

int main(){
    char str[36] = "XT namR iL smilP dsfsdag dsgsdg" ;
    reverseArray((char*)str,15);
    printf("%s\n",str);
    insertLength((char*)&str,('A'+(strlen(str))%26),0);
    printf("%s\n",str);
    return 0; 
}


void reverseArray(char *str,unsigned int length_str){
    char temp ;
    if(str == (str+length_str)){return;}
    temp = *str ; 
    *str = *(str+length_str); 
    *(str+length_str) = temp ; 
    reverseArray(str+1,length_str-1);
}

/* part 02 */
void insertLength(char str[],char var,int start)
{   
    if (*(str+start) == '\0' ) {return;}
    insertLength(str,var,start+1);
    if (isspace(*(str+start))) {
        *(str+start) = var;
    }
}
