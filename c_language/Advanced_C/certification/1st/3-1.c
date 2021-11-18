#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[101], cmp_word[11], replace_word[11], result_str[251] = {0,};
    char *p;
    int result_index = 0;

    gets(str);
    gets(cmp_word);
    gets(replace_word);


    for(p = str; p < str + strlen(str);){
        if(strncmp(p, cmp_word, strlen(cmp_word)) == 0){
            strcat(result_str, replace_word);
            p += strlen(cmp_word);
            result_index += strlen(replace_word);
        }
        else{
            result_str[result_index] = *p;
            result_index ++;
            p++;
        }
    }
    result_str[result_index] = '\0';

    printf("%s", result_str);



    return 0;
}