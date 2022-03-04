#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    
    scanf("%d", &n);

    int* list_a = (int*)malloc(sizeof(int) * n);
    int* list_b = (int*)malloc(sizeof(int) * n);
    int* list_result = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &list_a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &list_b[i]);
    }

    for(int i = 0; i < n; i++){
        list_result[i] = list_a[i] + list_b[n - i - 1];
    }

    for(int i = 0; i < n; i++){
        printf("%d ", list_result[i]);
    }
    
    return 0;
}