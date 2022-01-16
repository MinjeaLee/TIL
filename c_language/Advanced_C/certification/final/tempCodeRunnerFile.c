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
    char str[101], max_str[101], min_str[101], result[101], word_1[101], word_2[101];
    char **word_max, **word_min;
    int n, m1, m2;
    int max_len = -1, min_len = 101;
    int str_len;
    int word_min_count, word_max_count;

    scanf("%d %d %d", &n, &m1, &m2);
    getchar();
    for(int i = 0; i< n; i++){
        gets(str);
        str_len = strlen(str);
        if(str_len > max_len){
            max_len = str_len;
            strcpy(max_str, str);
        }
        if(str_len < min_len){
            min_len = str_len;
            strcpy(min_str, str);
        }
    }

    word_max = (char **) malloc(sizeof(char *));
    word_max_count = str_to_word(max_str, word_max);

    word_min = (char **) malloc(sizeof(char *));
    word_min_count = str_to_count(min_str, word_min);

    strcpy(word_1, word_max[m1]);
    strcpy(word_2, word_min[m2]);

    if(strcmp(word_1, word_2) < 0){
        strcpy(result, word_1);
        strcat(result, word_2);
    }
    else{
        strcpy(result, word_2);
        strcat(result, word_1);
    }
    printf("%s\n%s", max_str, min_str);
    printf("%s", result);

    for(int i = 0; i < word_max_count; i++){
        free(word_max[i]);
    }
    for(int i = 0; i < word_min_count; i++){
        free(word_min[i]);
    }
    free(word_max);
    free(word_min);

    return 0;
}