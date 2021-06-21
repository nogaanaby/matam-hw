#include "Graph.h"
#define N 7 

int main()
{
    int Group[3] = {5,4,3};
    int Adj[N + 1][N + 1];
    /*build up of the graph by the edges of the graph */
    int arr[][2] = {{1,2},{1,7},{2,6},{3,7},{2,4},{3,4},{4,5},{5,6},{6,7},{5,7},{2,3}};
    /*number  of edges  */
    M = sizeof(arr) / sizeof(arr[0]);
    createAdjMatrix(Adj,arr);
    printAdjMatrix(Adj);
    if(isMainGroup(Adj,7,Group,3))
        printf("True\n");
    else
        printf("False\n");
    return 0 ;
}


int isMainGroup(int Adj[][N + 1],int graph_N,int *Group, int group_M){
    int i,j,count_number_of_match_vertex = 0 , isEdge = 0 ;
    if(graph_N <= 0 && group_M >= 0 ){
        printf("error size of matrix or group is zero or nagitive \n");
        return 0 ;
    }
    /* chack for main group  */
    if(Group){
        /* check from zero to the the start of the group  */
        for(i=1 ; i < graph_N+1 ; i++){
            /* if i is in grop continue */
            if(isInGroup(i,Group,group_M)){continue;}
            for(j=1; j < graph_N+1 && !isEdge ; j++){
                /* if j is  */
                if(isInGroup(j,Group,group_M)){
                    if(Adj[i][j] == 1){
                        isEdge = 1;
                    }
                }
            }
            /* if you check all row and did not found a edge to the group return false */
            if(!isEdge){
                return 0 ;
            }
            isEdge = 0 ;
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


void createAdjMatrix(int Adj[][N + 1],int arr[][2]){
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            Adj[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {

        int x = arr[i][0];
        int y = arr[i][1];

        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}



void printAdjMatrix(int Adj[][N + 1])
{

    // Traverse the Adj[][]
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {

            // Print the value at Adj[i][j]
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}