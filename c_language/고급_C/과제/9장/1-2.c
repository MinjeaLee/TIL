#include <stdio.h>
#include <limits.h>

int *max(int *x);

int *min(int *x);

// 함수 원형 선언 마지막으로
int *low_address(int *a, int *b){
    int *add;
    if(a > b){
        add = b;
    }
    else{
        add = a;
    }
    return add;
}
int dif_address(int *a, int *b){
    int *high, *low;
    if(a > b){
        high = a;
        low = b;
    }
    else{
        low = a;
        high = b;
    }
    if(high - low <= 1){
        return 0;
    }
    else{
        return high - low;
    }
}

int main(){
    int n, arr[100];
    int *p_n = &n, *p_arr;
    int dif;


    scanf("%d", p_n);

    for(int i = 0; i < *p_n; i++){
        for(p_arr = arr; p_arr < arr + 100; p_arr++){
            scanf("%d", p_arr);
            if(*p_arr == 0){
                break;
            }
        }
        if(dif_address(max(arr), min(arr))){
            dif = dif_address(max(arr), min(arr));
            for(p_arr = low_address(max(arr), min(arr)) + 1; p_arr < low_address(max(arr), min(arr)) + dif; p_arr++){
                printf("%d ", *p_arr);
            }
            printf("\n");
        }
        else{
            printf("none\n");
        }
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

