#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **word_a, **word_b, **result;
    char str_a[101], str_b[101], *p_i, *tmp;
    int count_word_a = 0, len_word_a = 0, index_word_a = 0;
    int count_word_b = 0, len_word_b = 0, index_word_b = 0;
    int index_1d = 0, index_2d = 0;

    int same_count = 0;


    gets(str_a);
    gets(str_b);

    // str_a
    for(p_i = str_a; p_i < str_a + strlen(str_a); p_i++){
        if(*p_i == ' '){
            count_word_a++;
        }
    }
    count_word_a++;

    word_a = (char ** ) malloc(sizeof(char *) * count_word_a);
    if(word_a == NULL){
        return -1;
    }
    for(p_i = str_a; p_i < str_a + strlen(str_a); p_i++){
        if(*p_i != ' '){
            len_word_a++;
        }
        else{
            word_a[index_word_a] = (char *) malloc(sizeof(char) * len_word_a + 1);
            if(word_a[index_word_a] == NULL){
                return -1;
            }
            len_word_a = 0;
            index_word_a++;
        }
    }
    word_a[index_word_a] = (char *) malloc(sizeof(char) * len_word_a + 1);
    if(word_a[index_word_a] == NULL){
        return -1;
    }

    for(p_i = str_a; p_i < str_a + strlen(str_a); p_i++){
        if(*p_i != ' '){
            word_a[index_1d][index_2d] = *p_i;
            index_2d++;
        }
        else{
            word_a[index_1d][index_2d] = '\0';
            index_1d++;
            index_2d = 0;
        }
    }
    word_a[index_1d][index_2d] = '\0';
    index_1d = 0;
    index_2d = 0;

    // str_b
    for(p_i = str_b; p_i < str_b + strlen(str_b); p_i++){
        if(*p_i == ' '){
            count_word_b++;
        }
    }
    count_word_b++;

    word_b = (char ** ) malloc(sizeof(char *) * count_word_b);
    if(word_b == NULL){
        return -1;
    }
    for(p_i = str_b; p_i < str_b + strlen(str_b); p_i++){
        if(*p_i != ' '){
            len_word_b++;
        }
        else{
            word_b[index_word_b] = (char *) malloc(sizeof(char) * len_word_b + 1);
            if(word_b[index_word_b] == NULL){
                return -1;
            }
            len_word_b = 0;
            index_word_b++;
        }
    }
    word_b[index_word_b] = (char *) malloc(sizeof(char) * len_word_b + 1);
    if(word_b[index_word_b] == NULL){
        return -1;
    }

    for(p_i = str_b; p_i < str_b + strlen(str_b); p_i++){
        if(*p_i != ' '){
            word_b[index_1d][index_2d] = *p_i;
            index_2d++;
        }
        else{
            word_b[index_1d][index_2d] = '\0';
            index_1d++;
            index_2d = 0;
        }
    }
    word_b[index_1d][index_2d] = '\0';


    result = (char ** ) malloc(sizeof(char *));
    if(result == NULL){
        return -1;
    }

    for(int i = 0; i < count_word_a; i++){
        for(int j = 0; j < count_word_b; j++){
            if(strcmp(word_a[i], word_b[j]) == 0){
                realloc(result, sizeof(char *) * same_count + 1);
                if(result == NULL){
                    return -1;
                }
                result[same_count] = (char *) malloc(sizeof(char) * strlen(word_a[i]));
                if(result[same_count] == NULL){
                    return -1;
                }
                strcpy(result[same_count], word_a[i]);
                same_count++;
                break;
            }
        }
    }

    for(int i = 0; i < same_count - 1; i++){
        for(int j = 0; j < same_count - 1 - i; j++){
            if(strlen(result[j]) < strlen(result[j + 1])){
                tmp = result[j];
                result[j] = result[j+1];
                result[j+1] = tmp;
            }
            else if (strlen(result[j]) == strlen(result[j + 1])){
                if(strcmp(result[j], result[j + 1]) > 0){
                    tmp = result[j];
                    result[j] = result[j + 1];
                    result[j+1] = tmp;
                }
            }
        }
    }


    for(int i = 0; i < same_count; i++){
        printf("%s\n", result[i]);
    }
    for(int i = 0; i < count_word_a; i++){
        free(word_a[i]);
    }
    for(int i = 0; i < count_word_b; i++){
        free(word_b[i]);
    }
    for(int i = 0; i < same_count; i++){
        free(result[i]);
    }
    free(word_a);
    free(word_b);
    free(result);


    return 0;
}