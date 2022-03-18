#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// find maximum number of elements in array using recursion
int max(int a[], int n){
    if(n == 1){
        return a[0];
    }
    else{
        int max_num = max(a, n - 1);
        if(max_num > a[n - 1]){
            return max_num;
        }
        else{
            return a[n - 1];
        }
    }
}

int main(){
    int arr[20];
    int n, max_num;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    max_num = max(arr, n);

    printf("%d\n", max_num);
    
    return 0;
}