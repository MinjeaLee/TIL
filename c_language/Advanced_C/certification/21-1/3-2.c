#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_word(char *str, char **word){
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
    int a_word_count, b_word_count, same_count = 0;
    char str_a[101], str_b[101], tmp[101];
    char **word_a, **word_b, result[50][50];
    int result_index = 0;

    gets(str_a);
    word_a = (char **)malloc(sizeof(char *));
    a_word_count = str_to_word(str_a, word_a);

    gets(str_b);
    word_b = (char **)malloc(sizeof(char *));
    b_word_count = str_to_word(str_b, word_b);

    for(int i = 0; i < a_word_count; i++){
        for(int j = 0; j < b_word_count; j++){
            if(strcmp(word_a[i], word_b[j]) == 0){
                strcpy(result[same_count], word_a[i]);
                same_count++;
            }
        }
    }

    for(int i = 0; i < same_count - 1; i++){
        for(int j = 0; j < same_count - 1 - i; j++){
            if(strlen(result[j]) < strlen(result[j + 1])){
                strcpy(tmp, result[j]);
                strcpy(result[j], result[j + 1]);
                strcpy(result[j + 1], tmp);
            }
            else if(strlen(result[j]) == strlen(result[j + 1])){
                if(strcmp(result[j], result[j + 1]) > 0){
                    strcpy(tmp, result[j]);
                    strcpy(result[j], result[j + 1]);
                    strcpy(result[j + 1], tmp);
                }
            }
        }
    }

    printf("%d\n", same_count);
    for(int i = 0; i < same_count; i++){
        printf("%s ", result[i]);
    }
    free(word_b);
    free(word_a);


    return 0;
}