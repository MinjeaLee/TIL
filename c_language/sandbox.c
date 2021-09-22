#include <stdio.h>

void swap(char *x, char *y){
    char tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    char str_2[] = "123";
    int len_2 = 3;

    for(int i = 0; i < len_2 / 2; i++){
        swap(str_2 + i, str_2 + len_2 - 1 - i);
    }

    
    printf("%s", str_2);

    return 0;
}