#include <stdio.h>

int main(){
    // char a[3] = "123";
    char str[6];
    scanf("%s", str);

    str[5] = '?';

    printf("%s", str);

    return 0;
}