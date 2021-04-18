#include <stdio.h>

#define N 4

void Resize(int *matrix_in,int *matrix_out);
// helpar func // 
void print_num_to_matrix(int *matrix,int num,int row,int col);
void print_matrix(int *matrix,int size);

int main(){
    int matrix[N][N] = {3,2,12,9,34,6,7,90,30,15,2,7,9,12,18.47} ;
    int matrix_out[2*N][2*N] = {0}; 
    printf("before \n\n");  
    print_matrix((int*)matrix,0);
    Resize((int*)matrix,(int*)matrix_out);
    printf("\n"); 
    printf("after \n\n"); 
    print_matrix((int*)matrix_out,2*N);
    return 0; 
}

void Resize(int *matrix_in,int *matrix_out){
    for(int i  = 0 ,row_i_jump = 0 ; i < N ; i++,row_i_jump +=2){
        for(int j = 0 ,col_i_jump = 0; j < N ; j++,col_i_jump +=2){
            print_num_to_matrix(matrix_out,matrix_in[i * N + j],row_i_jump,col_i_jump);
        }
    }
}

void print_num_to_matrix(int *matrix,int num,int row,int col){
    for(int i = row ; i < 2*N ; i++){
        for(int j = col; j < 2*N ; j++){
            matrix[i * (2*N) + j] = num ;  
        }
    }
}



// helpar func => print matrix the check resualt  // 
void print_matrix(int *matrix,int size){
    size = (size == 0 ) ? N : size;
    for(int i = 0 ; i < size ; i++){
        printf("[");
        for(int j = 0 ; j < size ;j++ ){
            printf("%d ,",matrix[i * size + j]);
        }
        printf("]\n");   
    }   
}

