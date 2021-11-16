#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_row(int **p, int M, int N){
    int count_zero;
    int max_count = -1;
    int seq_check = 0;

    for(int i = 0; i < M; i++){
        count_zero = 0;
        for(int j = 0; j < N; j++){
            if(seq_check == 1 && p[i][j] == 0){
                count_zero ++;
                seq_check = 1;
            }
            else if(seq_check == 1 && p[i][j] != 0){
                seq_check = 0;
                count_zero = 0;
            }
            else if(seq_check == 0 && p[i][j] == 0){
                seq_check = 1;
                count_zero++;
            }
            else if(seq_check == 0 && p[i][j] != 0){
                seq_check = 0;
                count_zero = 0;
            }
            if(max_count < count_zero){
                max_count = count_zero;
            }
        }
    }

    return max_count;
}

int check_col(int **p, int M, int N){
    int count_zero;
    int max_count = -1;
    int seq_check = 0;

    for(int i = 0; i < N; i++){
        count_zero = 0;
        for(int j = 0; j < M; j++){
            
            if(seq_check == 1 && p[j][i] == 0){
                count_zero ++;
                seq_check = 1;
            }
            else if(seq_check == 1 && p[j][i] != 0){
                seq_check = 0;
                count_zero = 0;
            }
            else if(seq_check == 0 && p[j][i] == 0){
                seq_check = 1;
                count_zero++;
            }
            else if(seq_check == 0 && p[j][i] != 0){
                seq_check = 0;
                count_zero = 0;
            }
            if(max_count < count_zero){
                max_count = count_zero;
            }
        }
    }

    return max_count;

}

int main(){
    int **list;
    int m, n;
    int x, y, z; // x -> index_1d, y -> index_2d, z -> value
    int row_zero, col_zero;

    scanf("%d %d", &m, &n);
    list = (int **) calloc(m, sizeof(int *));
    for(int i = 0; i < m; i++){
        list[i] = (int *) calloc(n, sizeof(int));
    }
    while(1){
        scanf("%d %d %d", &x, &y, &z);
        if(x == 0 && y == 0 && z == 0){
            break;
        }
        list[x][y] = z;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf(" %d", list[i][j]);
        }
        printf("\n");
    }

    row_zero = check_row(list, m, n);
    col_zero = check_col(list, m, n);

    if(row_zero > col_zero){
        printf("%d", row_zero);
    }
    else{
        printf("%d", col_zero);
    }

    for(int i = 0; i < m; i++){
        free(list[i]);
    }
    free(list);
        

    return 0;
}