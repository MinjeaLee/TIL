#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// GCD using recursion
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

int main(){
    int a, b, result;


    scanf("%d %d", &a, &b);
    result = gcd(a, b);
    printf("%d\n", result);

    return 0;
}