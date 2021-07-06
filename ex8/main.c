#include "ex8.h"

int main(){
    /* part1 */
    FILE *fp = open_for_read_write("text.txt","r");
    Node *word_list = NULL;
    char* new_name_file = create_new_file_name("text.txt","_rpl.txt");
    FILE *fp_write = fopen(new_name_file,"w");
    get_sentence_from_file(new_name_file,&word_list,fp,fp_write);
    clear(new_name_file,word_list,fp,fp_write);
    /* part2 */
    fp = open_for_read_write(new_name_file,"r");
    char* new_name = create_new_file_name(new_name_file,"_band.txt");
    printf(": %s \n",new_name);
    fp_write = fopen(new_name,"w");
    fclose(fp);
    fp = fopen(new_name,"r");
    encryption_file(fp_write,fp);
    clear(new_name_file,word_list,fp,fp_write);
    return 0 ; 
}