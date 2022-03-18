#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// count the number of specific character in a string using recursion
int count(char *str, char ch){
    if(*str == '\0'){
        return 0;
    }
    else{
        if(*str == ch){
            return 1 + count(str + 1, ch);
        }
        else{
            return count(str + 1, ch);
        }
    }
}   

int main(){
    char str[101];    
    char character;

    int count_char;

    gets(str);
    scanf("%c", &character);

    count_char = count(str, character);

    printf("%d\n", count_char);

    return 0;
}