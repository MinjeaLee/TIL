#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str_a[101], str_b[101];
    char *p, *tmp, *cmp_word;
    char **word_a, **word_b, **result;
    int result_index_1d = 0;
    int same_word_count = 0;
    int a_blank_count = 0, a_index_1d = 0, a_index_2d = 0;
    int b_blank_count = 0, b_index_1d = 0, b_index_2d = 0;
    int a_word_len = 0;
    int b_word_len = 0;
    int cmp_word_len;

    gets(str_a);
    gets(str_b);

    for(p = str_a; *p != '\0'; p++){
        if(*p == ' '){
            a_blank_count++;
        }
    }
    a_blank_count++;

    word_a = (char **) malloc(sizeof(char *) * a_blank_count);

    for(p = str_a; *p != '\0'; p++){
        if(*p != ' '){
            a_word_len++;
        }
        else{
            word_a[a_index_1d++] = (char *) malloc(sizeof(char) * a_word_len + 1);
            a_word_len = 0;
        }
    }
    word_a[a_index_1d] = (char *) malloc(sizeof(char) * a_word_len + 1);

    a_index_1d = 0;
    for(p = str_a; *p != '\0'; p++){
        if(*p != ' '){
            word_a[a_index_1d][a_index_2d++] = *p;
        }
        else{
            word_a[a_index_1d][a_index_2d] = '\0';
            a_index_1d++;
            a_index_2d = 0;
        }
    }
    word_a[a_index_1d][a_index_2d] = '\0';


    for(p = str_b; *p != '\0'; p++){
        if(*p == ' '){
            b_blank_count++;
        }
    }
    b_blank_count++;      // -> word count

    word_b = (char **)malloc(sizeof(char *) * b_blank_count);

    for(p = str_b; *p != '\0'; p++){
        if(*p != ' '){
            b_word_len++;
        }
        else{
            word_b[b_index_1d++] = (char *)malloc(sizeof(char) * b_word_len + 1);
            b_word_len = 0;
        }
    }
    word_b[b_index_1d++] = (char *)malloc(sizeof(char) * b_word_len + 1);

    b_index_1d = 0;
    for(p = str_b; *p != '\0'; p++){
        if(*p != ' '){
            word_b[b_index_1d][b_index_2d++] = *p;
        }
        else{
            word_b[b_index_1d][b_index_2d] = '\0';
            b_index_2d = 0;
            b_index_1d++;
        }
    }
    word_b[b_index_1d][b_index_2d] = '\0';


    for(int i = 0; i < a_blank_count; i++){
        for(int j = 0; j < a_blank_count; j++){
            if(i == j){
                continue;
            }
            cmp_word_len = strlen(word_a[i]) + strlen(word_a[j]);
            cmp_word = (char *)malloc(sizeof(char) * cmp_word_len + 1);
            strcpy(cmp_word, word_a[i]);
            strcat(cmp_word, word_a[j]);
            for(int k = 0; k < b_blank_count; k++){
                if(strcmp(cmp_word, word_b[k]) == 0){
                    same_word_count ++;
                    break;
                }
            }
        }
    }

    result = (char **) malloc(sizeof(char *) * same_word_count);

    for(int i = 0; i < a_blank_count; i++){
        for(int j = 0; j < a_blank_count; j++){
            if(i == j){
                continue;
            }
            cmp_word_len = strlen(word_a[i]) + strlen(word_a[j]);
            cmp_word = (char *)malloc(sizeof(char) * cmp_word_len + 1);
            strcpy(cmp_word, word_a[i]);
            strcat(cmp_word, word_a[j]);
            for(int k = 0; k < b_blank_count; k++){
                if(strcmp(cmp_word, word_b[k]) == 0){
                    result[result_index_1d] = (char *) malloc(sizeof(char) * strlen(word_b[k]) + 1);
                    strcpy(result[result_index_1d++], word_b[k]);
                }
            }
        }
    }
    

    for(int i = 0; i < same_word_count - 1; i++){
        for(int j = 0; j < same_word_count - 1 - i; j++){
            if(strcmp(result[j], result[j + 1]) == 0){
                strcpy(result[j + 1], "\0");
            }
            if(strlen(result[j]) < strlen(result[j + 1])){
                tmp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tmp;
            }
            else if (strlen(result[j]) == strlen(result[j + 1])){
                if(strcmp(result[j], result[j + 1]) > 0){
                    tmp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = tmp;
                }
            }
            
        }
    }

    for(int i = 0; i < same_word_count; i++){
        if(result[i] != "\0"){
            printf("%s\n", result[i]);
        }
    }

    for(int i = 0; i < a_blank_count; i++){
        free(word_a[i]);
    }
    for(int i = 0; i < b_blank_count; i++){
        free(word_b[i]);
    }
    for(int i = 0; i < same_word_count; i++){
        free(result[i]);
    }
    free(word_a);
    free(word_b);
    free(result);
    

    return 0;
}