#include "ex8.h"

int main(){
    /* part1 */
    FILE *fp = open_for_read_write("text.txt","r");
    Node *word_list = NULL;
    char* new_name_file = create_new_file_name("text.txt","_rpl.txt");
    FILE *fp_write = fopen(new_name_file,"w+");
    get_sentence_from_file(new_name_file,&word_list,fp,fp_write);
    fclose(fp);
    /* part2 */
    char* new_name = create_new_file_name("text.txt","_band.txt");
    /*now fp_write is the file we want to read from text_rpl.txt 
    and  fp is the file we write to text_band.txt*/
    fp = fopen(new_name,"w");
    printf(" %s \n",new_name);
    encryption_file(fp_write,fp);
    clear(new_name,word_list,fp,fp_write);
    return 0 ; 
}