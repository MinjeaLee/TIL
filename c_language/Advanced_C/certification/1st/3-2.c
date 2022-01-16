#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char str_a[101], str_b[101], result[251] = {0,};
    char word_a[50][50], word_b[50][50];
    int word_index_1d = 0, word_index_2d = 0;
    int a_word_count = 0, b_word_count = 0;
    char *p;
    int replace_word_index = 0;
    int result_index = 0;

    gets(str_a);
    gets(str_b);

    for(p = str_a; *p != '\0'; p++){
        if(*p != ' '){
            word_a[word_index_1d][word_index_2d++] = *p;
        }
        else{
            // word_a[word_index_1d][word_index_2d] = '\0';
            a_word_count++;
            word_index_1d++;
            word_index_2d = 0;
        }
    }
    word_a[word_index_1d][word_index_2d] = '\0';
    a_word_count++;

    word_index_1d = 0;
    word_index_2d = 0;

    for(p = str_b; *p != '\0'; p++){
        if(*p != ' '){
            word_b[word_index_1d][word_index_2d++] = *p;
        }
        else{
            // word_b[word_index_1d][word_index_2d] = '\0';
            b_word_count++;
            word_index_1d++;
            word_index_2d = 0;
        }
    }
    // word_b[word_index_1d][word_index_2d] = '\0';
    b_word_count++;


    for(int i = 0; i < a_word_count - 1; i++){
        for(int j = i + 1; j < a_word_count; j++){
            if(strcmp(word_a[i], word_a[j]) == 0){
                strcpy(word_a[j], word_b[replace_word_index++]);
            }
        }
    }

    int i = 0;

    for(i = 0, p = result; i < a_word_count - 1; i++){
        strcat(p, word_a[i]);
        p += strlen(word_a[i]);
        *p = ' ';
        p += 1;
    }
    strcpy(result + strlen(result), word_a[a_word_count - 1]);

    printf("%s\n", result);


    return 0;
}