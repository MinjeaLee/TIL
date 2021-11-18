#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num_of_divisors(int M, int *arr){
    int count = 0;
    
    for(int i = 1; i <= M; i++){
        if(M % i == 0){
            arr[count] = i;
            count++;
        }
    }
    if(count <= 20){
        return count;
    }
    else{
        return -1;
    }
}

int cal_sum(int *onearr, int size){
    int *p;
    int total = 0;

    for(p = onearr; p < onearr + size; p++){
        if(p == NULL){
            break;
        }
        total += *p;
    }
    return total;
}

int main(){
    int n, m, k, tmp_num, total;
    int **darr, *num, temp[20];
    int max = -1, max_index;
    scanf("%d", &n);
    darr = (int **)malloc(sizeof(int *) * n);
    num = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        num[i] = num_of_divisors(m, temp);
        darr[i] = (int *)malloc( sizeof(int) * num[i] );
        for(int j = 0; j < num[i]; j++){
            darr[i][j] = temp[j];
        }
    }
    scanf("%d", &k);
    
    for(int i = 0; i < num[k] - 1; i++){
        for(int j = 0; j < num[k] - 1 - i; j++){
            if(darr[k][j] < darr[k][j + 1]){
                tmp_num = darr[k][j];
                darr[k][j] = darr[k][j + 1];
                darr[k][j + 1] = tmp_num;
            }
        }
    }
    if(num[k] != -1){
        for(int i = 0; i < num[k]; i++){
        printf("%d ", darr[k][i]);
        }
        printf("\n");
    }
    else{
        printf("-1\n");
    }
    

    for(int i = 0; i < n; i++){
        total = cal_sum(darr[i], num[i]);
        if(total > max){
            max = total;
        }
    }

    printf("%d\n", max);

    for(int i = 0; i < n; i++){
        free(darr[i]);
    }
    free(darr);
    free(num);

    return 0;
}

/*
3 
10 20 30
1
*/
/*
5
100 500 1000 5 3
0
*/
/*
3
1000 10000 100
1
*/