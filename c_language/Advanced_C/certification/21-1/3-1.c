#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_word_return_word_count(char *str, char **word){
    char *p;
    int word_count = 0, len_word = 0, index_1d = 0, index_2d = 0;

    for(p=str; *p != NULL; p++){
        if(*p == ' '){
            word_count++;
        }
    }
    word_count++;

    word = (char **)realloc(word, sizeof(char *) * word_count);

    for(p = str; *p != NULL; p++){
        if(*p != ' '){
            len_word++;
        }
        else{
            word[index_1d] = (char *)malloc(sizeof(char) * len_word + 1);
            len_word = 0;
            index_1d++;
        }
    }
    word[index_1d] = (char *)malloc(sizeof(char) * len_word + 1);

    index_1d = 0;

    for(p = str; *p != NULL; p++){
        if(*p != ' '){
            word[index_1d][index_2d++] = *p;
        }
        else{
            word[index_1d][index_2d] = NULL;
            index_1d++;
            index_2d = 0;
        }
    }
    word[index_1d][index_2d] = NULL;

    return word_count;
}


int main(){
    char str_a[101], str_b[101];
    char **word_a, **word_b, result[50][50];
    int a_word_count, b_word_count;
    int same_count = 0, result_index = 0;

    gets(str_a);
    gets(str_b);

    word_a = (char **) malloc(sizeof(char *));
    a_word_count = str_to_word_return_word_count(str_a, word_a);

    word_b = (char **) malloc(sizeof(char *));
    b_word_count = str_to_word_return_word_count(str_b, word_b);

    for(int i = 0; i < a_word_count; i++){
        for(int j = 0; j < b_word_count; j++){
            if(strcmp(word_a[i], word_b[j]) == 0){
                same_count++;
                strcpy(result[result_index], word_a[i]); 
                result_index++;
                break;
            }
        }
    }

    printf("%d\n", same_count);
    for(int i = 0; i < same_count; i++){
        printf("%s\n", result[i]);
    }

    return 0;
}