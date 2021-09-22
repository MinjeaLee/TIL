#include <stdio.h>
#include <limits.h>

int *max(int *x);

int *min(int *x);

int main(){
    int n, arr[100];
    int *p_n = &n, *p_arr;

    scanf("%d", p_n);

    for(int i = 0; i < *p_n; i++){
        for(p_arr = arr; p_arr < arr + 100; p_arr++){
            scanf("%d", p_arr);
            if(*p_arr == 0){
                break;
            }
        }
        printf("%d %d\n", *max(arr), *min(arr));
    }

    return 0;
}

int *max(int *x){
    int max = INT_MIN;
    int *p_max = &max;
    for(int *p = x; *p != 0; p++){
        if(*p > max){
            max = *p;
            p_max = p;
        }
    }
    return p_max;
}

int *min(int *x){
    int min = INT_MAX;
    int *p_min = &min;
    for(int *p = x; *p != 0; p++){
        if(*p < min){
            min = *p;
            p_min = p;
        }
    }
    return p_min;
}
