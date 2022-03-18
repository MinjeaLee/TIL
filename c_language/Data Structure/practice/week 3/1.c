#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1 ~ n sum use recursion
int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}


int main(){
    int n;

    scanf("%d", &n);

    printf("%d\n", sum(n));

    return 0;
}