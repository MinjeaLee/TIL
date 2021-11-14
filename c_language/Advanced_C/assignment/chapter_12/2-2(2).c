#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_word_return_word_count(char * str, char **word){
    char *p;
    int blank_count = 0, index_1d = 0, index_2d = 0;
    int word_len = 0;

    for(p = str; *p != '\0'; p++){
        if(*p == ' '){
            blank_count++;
        }
    }
    blank_count++;      // -> word count

    word = (char **)malloc(sizeof(char *) * blank_count);

    for(p = str; *p != '\0'; p++){
        if(*p != ' '){
            word_len++;
        }
        else{
            word[index_1d++] = (char *)malloc(sizeof(char) * word_len + 1);
            word_len = 0;
        }
    }
    word[index_1d++] = (char *)malloc(sizeof(char) * word_len + 1);

    index_1d = 0;
    for(p = str; *p != '\0'; p++){
        if(*p != ' '){
            word[index_1d][index_2d++] = *p;
        }
        else{
            word[index_1d][index_2d] = '\0';
            index_2d = 0;
            index_1d++;
        }
    }
    word[index_1d][index_2d] = '\0';

    return blank_count;
}


int main(){
    char str_a[101], str_b[101];
    char *p, *tmp;
    char **word_a, **word_b, **result;
    int result_index_1d = 0;
    int same_word_count = 0;
    int a_blank_count = 0, a_index_1d = 0, a_index_2d = 0;
    int b_blank_count = 0, b_index_1d = 0, b_index_2d = 0;
    int a_word_len = 0;
    int b_word_len = 0;


    gets(str_a);
    gets(str_b);
    
    for(p = str_a; *p != '\0'; p++){
        if(*p == ' '){
            a_blank_count++;
        }
    }
    a_blank_count++;      // -> word count

    word_a = (char **)malloc(sizeof(char *) * a_blank_count);

    for(p = str_a; *p != '\0'; p++){
        if(*p != ' '){
            a_word_len++;
        }
        else{
            word_a[a_index_1d++] = (char *)malloc(sizeof(char) * a_word_len + 1);
            a_word_len = 0;
        }
    }
    word_a[a_index_1d++] = (char *)malloc(sizeof(char) * a_word_len + 1);

    a_index_1d = 0;
    for(p = str_a; *p != '\0'; p++){
        if(*p != ' '){
            word_a[a_index_1d][a_index_2d++] = *p;
        }
        else{
            word_a[a_index_1d][a_index_2d] = '\0';
            a_index_2d = 0;
            a_index_1d++;
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
        for(int j = 0; j < b_blank_count; j++){
            if(strcmp(word_a[i], word_b[j]) == 0){
                same_word_count++;
                break;
            }
        } 
    }

    result = (char **) malloc(sizeof(char *) * same_word_count);
    for(int i = 0; i < a_blank_count; i++){
        for(int j = 0; j < b_blank_count; j++){
            if(strcmp(word_a[i], word_b[j]) == 0) {
                result[result_index_1d] = (char *) malloc(sizeof(char) * strlen(word_a[i]) + 1);
                strcpy(result[result_index_1d], word_a[i]);
                result_index_1d++;
            }
        }
    }

    for(int i = 0; i < same_word_count - 1; i++){
        for(int j = 0; j < same_word_count - 1 - i; j++){
            if(strlen(result[j]) < strlen(result[j + 1])){
                tmp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tmp;
            }
            else if(strlen(result[j + 1]) == strlen(result[j])){
                if(strcmp(result[j], result[j + 1]) > 0){
                    tmp = result[j];
                    result[j] = result[j+1];
                    result[j + 1] = tmp;
                }
            }
        }
    }

    for(int i = 0; i < same_word_count; i++) {
        printf("%s\n", result[i]);
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