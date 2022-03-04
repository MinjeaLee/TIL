#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int n;
    int result = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        result += sum(i);
    }

    printf("%d", result);

    return 0;
}