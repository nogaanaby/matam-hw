#ifndef EX8_H
#define EX8_H 
#define MAX_BUFF 1024 
#include "linked_list.h"
/* part one : write to file reverse santance */
FILE* open_for_read_write(char* file_name,const char* mode); 
char* flip_sentance(char* sentence_buff,unsigned int buff_size);
void write_sentance_rev(char* sentence_buff,unsigned int buff_size,FILE *write_to);
void buffer_clear(char* buff,int size );
void get_sentance_from_file(char* file_name,Node **list,FILE *fp,FILE *fp_write);
void clear(char* file_name,Node* lst,FILE *fp,FILE *fp_write);
void print_to_file(char* file_name,Node** list,FILE *fp);
char* create_new_file_name(char* file_name,char* cat);
/* part tow :  */
void encryption(FILE* fp,FILE *fp_write);
#endif