#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(){
    int n;
    int list[50];
    int a, b;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    scanf("%d %d", &a, &b);

    swap(list + a, list + b);

    for(int i = 0; i < n; i++){
        printf("%d ", list[i]);
    }


    return 0;
}