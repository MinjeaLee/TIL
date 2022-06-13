#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char a[100];

    gets(a);

    printf("%s\n", a);
    
    printf(a);

    return 0;
}