#include "Graph.h"

int isMainGroup(int **Graph,int graph_N, int *Group, int group_M){
    int i,j,count_number_of_match_vertex = 0 ; 
    if(graph_N <= 0 && group_M >= 0 ){
        printf("error size of matrix or group is zero or nagitive \n");
        return 0 ; 
    }
    /* chack for main group  */
    if(Graph && Group){
        /* check from zero to the the start of the group  */
        for(i=0 ; i < graph_N ; i++){
            /* if i is in grop continue */
            if(isInGroup(i,Group,group_M)){continue;}
            for(j=0; j < graph_N ; j++){
                
            }
        }


    }
    return 1; 
}

/* check if i is in group  */
int isInGroup(int number_to_find,int *Group,int size_group){
    int i ; 
    for(i = 0 ; i < size_group; i++){
        if(*(Group+i) == number_to_find){
            return 1;
        }
    }
    return 0 ; 
}