#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal(int n){
    if(n >= 10){
        cal(n / 10);
        printf("%d\n", n % 10);
    }
    else{
        printf("%d\n", n);
    }
}

int main(){
    int n;

    scanf("%d", &n);
    cal(n);

    return 0;
}