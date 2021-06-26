#include <stdio.h>

int len(char x[]){
    int result = 0;
    while (x[result] != 0)
    {
        result++;
    }
    return result;
}

int main(){
    char a[] = "Don't worry, Be happy!";
    char b[] = "걱정마, 행복할 거야.";
    int a_len, b_len;

    a_len = len(a);
    b_len = len(b);

    printf("a_len = %d\nb_len = %d\n", a_len, b_len);
    printf("%s\n%s", a, b);

    return 0;
}