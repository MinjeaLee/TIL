#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input(int *p){
    int *p_arr;

    for(p_arr = p; ;p_arr++){
        scanf("%d", p_arr);
        if(*p_arr == -1){
            break;
        }
    }

    return p_arr - p;

}

int *sel_next(int *p){
    int *p_arr;
    int sum = 0;
    for(p_arr = p;; p_arr++){
        if(*p_arr == -1){
            p_arr--;
            break;
        }
        sum += *p_arr;
        if(sum > 10){
            p_arr--;
            break;
        }
    }

    return p_arr;

}
int number(int *p, int *q){
    int *p_arr;
    int result = 0;
    for(p_arr = p; p_arr <= q; p_arr++){
        result *= 10;
        result += *p_arr;
    }
    
    return result;
}

int main(){
    int arr[100];
    int len_arr, output;
    int *p_start, *p_end;

    len_arr = input(arr);
    
    for(p_start = arr; p_start < arr + len_arr;){
        p_end = sel_next(p_start);
        output = number(p_start, p_end);
        p_start = p_end + 1;
        printf("%d*\n", output);
    }


    return 0;
}