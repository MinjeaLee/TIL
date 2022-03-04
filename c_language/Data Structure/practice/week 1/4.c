#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// make func shift one char position to right 
void shift_right(char *str){
    int len = strlen(str);
    char start_letter = *(str);

    for(int i = 0; i < len; i++){ 
        *(str + i) = *(str + i + 1);
    }
    *(str + len - 1) = start_letter;
}

int main(){
    char string[101];
    int len;

    scanf("%s", string);

    len = strlen(string);

    printf("%s\n", string);
    for(int i = 0; i < len - 1; i++){
        shift_right(string);
        printf("%s\n", string);
    }
    

    return 0;
}