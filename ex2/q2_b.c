#include <stdio.h>

#define N 4


void print_diagonal_matrix(int *matrix);
// helper func//
void print_diagnole(int row,int *matrix);
void printMat(int *mat);


int main(){
    int matrix[N][N] = {3,2,12,9,34,6,7,90,30,20,15,4,8,63,3,5} ;
    printMat((int*)matrix);
    printf("\n");
    printf("print diagnole : \n");
    printf("\n");
    print_diagonal_matrix((int*)matrix);   
    return 0; 
}

void print_diagnole(int row,int *matrix)
{
        for(int j = 0 , k = row; j <= row ; j++,k--){
            printf(" %d " ,matrix[k * N + j]);
        }
         printf("\n");
}


void print_diagnole_second_part(int row,int *matrix)
{
        for(int j = 0 , k = row; j <= row ; j++,k--){
            printf(" %d " ,matrix[ k * N + j]);
        }
         printf("\n");
}


// helpar func => print matrix the check resualt  // void printMatrix(int (*matrix)[COLS], int rows, int cols)
void print_diagonal_matrix(int *matrix)
{
    //print first  diagnoal index (0,0)//
    printf(" %d ",matrix[0]);
    printf("\n");

    for(int i = 1; i < N; i++){
        print_diagnole(i,(int*)matrix);
    }

    for(int i = 0  ; i < N/2 ; i++){
        for(int j = i+1 , k = N-1 ; j < N   ; j++,k--){
            printf(" %d " ,matrix[ k * N + j]);
        }
        printf("\n");
    }
    //print last  diagnoal index (n-1,n-1)//
    printf(" %d ",matrix[(N*N)-1]);
   
}

void printMat(int *mat){
    printf("orignal matrix : \n");
    printf("\n");
    for(int i = 0;i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d,",mat[i * N + j]); 
        }
        printf("\n");
    }
}