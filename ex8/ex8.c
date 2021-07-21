#include "ex8.h"

FILE* open_for_read_write(char* file_name,const char* mode){
    FILE *fp ; 
    fp = fopen(file_name,mode);
    if(fp == NULL){
        printf("for file : %s  can't open file ! exit program !\n",file_name);
        perror("fopen fail");
        exit(1);
    }
    return fp;
} 

void get_sentence_from_file(char* file_name,Node **list,FILE *fp,FILE *fp_write){
    char temp_buff[MAX_BUFF] ={0}, *token;
    char c ;
    int i = 1 ; 
    /* add the space to the lest elment  in the new list, becuse there is no space 
    in the end of the sentence */
    temp_buff[0] = ' '; 
    for( i = 1 ; (c = fgetc(fp)) != EOF &&  i < MAX_BUFF ; i++){
            if(c == ' '){
                temp_buff[i+1] = '\0';
                addToList(list,temp_buff); 
                buffer_clear(temp_buff,i+1);
                i = 0 ;
            }else if(c == '.'){
                /* end of sentence */
                temp_buff[i+1] = '\0';
                token = strtok(temp_buff,"\n");
                addToList(list,token);
                addToList(list,".");
                print_to_file(file_name,list,fp_write);
                /* clear the buffer  */
                memset(temp_buff,0,MAX_BUFF);   
                /* ignore end of line */    
            }
        temp_buff[i] = c ; 
    }
}

/* print one revarse sentence  to new file */
void print_to_file(char* file_name,Node **list,FILE *fp){
    Node *temp = *list;
    char* data; 
    int i = 0 ,size = countListElements(temp); 
    if(fp){
        for(i = 0 ; i < size ; i++ ){
            data = pop_data_and_remove(list);
            fputs(data,fp);
            removeFirstFromList(list);
            /* free alloc data from pop_data_and_remove  */
            free(data);
        }
        fputs("\n",fp);
    }else{
        printf("Error can't open the file exit prog\n");
        exit(1);
    }
}

/* take the old file name and create a new file name => <old_name>_rpl.txt */
char* create_new_file_name(char* file_name,char* cat){
    char* token,*new_file_name;
    /* add space for string  "_rpl" */
    new_file_name = (char*) malloc (sizeof(char)*(strlen(file_name)+4));
    strcpy(new_file_name,file_name);
    token = strtok(new_file_name,".");
    strcpy(new_file_name,token);
    strcat(new_file_name,cat);
    return new_file_name;
}

void buffer_clear(char* buff,int size ){
    int i = 0 ; 
    for(i = 0 ; i < size ; i++){
        buff[i] = 0 ; 
    }
}

void clear(char* file_name,Node* lst,FILE *fp,FILE *fp_write){
    destroyList(&lst);
    free(file_name);
    fclose(fp);
    fclose(fp_write);
}

/* part2 */
void encryption_file(FILE* fp,FILE *fp_write){
    int i = 0 ;
    char c ;  
    long start = 0 , end = 1 ;
    if(fp && fp_write){
        /*calc the size of the file*/
        for(i = 0 ; start < end  ; i++){
            /* move corsur  to the start  */
            fseek(fp,i,SEEK_SET);
            start = ftell(fp);
            c = (char) fgetc(fp);
            fputc(c,fp_write);
            /* move corsur to the end */
            fseek(fp,-i,SEEK_END);
            end = ftell(fp);
            c = (char) fgetc(fp);
            fputc(c,fp_write);
        }
    }
}

