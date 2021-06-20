#ifndef GRAPH_h
#define GRAPH_h
#include <stdio.h> 
#include <stdlib.h>
int isInGroup(int number_to_find,int *Group,int size_group);
int N,M;
int isMainGroup(int **Adj,int graph_N, int *Group, int group_M);
void printAdjMatrix(int **Adj);
void createAdjMatrix(int **Adj,int arr[][2]);
int** init_matrix(int size);
void free_matrix(int **arr,int size);
#endif