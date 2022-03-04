#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void ABC(int list[], int k){
    int max = INT_MIN;
    int max_index;
    int tmp;

    for(int i = k; i < 10; i++){
        if(list[i] >= max){
            max = list[i];
            max_index = i;
        }
    }

    tmp = *(list + k);
    *(list + k) = *(list + max_index);
    *(list + max_index) = tmp;
}

int main(){
    int list[10];

    for(int i = 0; i < 10; i++){
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < 9; i++){
        ABC(list, i);
    }

    for(int i = 0; i < 10; i++){
        printf(" %d", list[i]);
    }

    return 0;
}