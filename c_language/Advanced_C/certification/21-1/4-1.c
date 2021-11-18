#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num_of_divisors(int M, int *arr){
    int arr_index = 0;

    for(int i = 1; i <= M; i++){
        if(M % i == 0){
            arr[arr_index++] = i;
            continue;
        }
    }
    if(arr_index > 20){
        return -1;
    }
    else{
        return arr_index;
    }

}

int main(){
    int m, num, tmp;
    int *arr;

    scanf("%d", &m);
    arr = (int *)malloc( sizeof(int) * 20);
    if(arr == NULL){
        return -1;
    }
    num = num_of_divisors(m, arr);

    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - 1- i; j++){
            if(arr[j] < arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }


    if(num != -1){
        for(int i = 0; i < num; i++){
           printf("%d ", arr[i]);
        }
    }
    else{
        printf("none");
    }

    free(arr);

    return 0;
}