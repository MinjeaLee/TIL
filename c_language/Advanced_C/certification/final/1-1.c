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
    char str_a[101], str_b[101];
    char **word_a,  **word_b;
    char word_1[101], word_2[101];
    int a_index, b_index;
    char result[101];
    int a_word_count, b_word_count;
    
    scanf("%d %d", &a_index, &b_index);
    getchar();

    gets(str_a);
    word_a = (char **)malloc(sizeof(char *));
    a_word_count = str_to_word(str_a, word_a);


    gets(str_b);
    word_b = (char **)malloc(sizeof(char *));
    b_word_count = str_to_word(str_b, word_b);

    strcpy(word_1, word_a[a_index]);
    strcpy(word_2, word_b[b_index]);

    if(strcmp(word_1, word_2) < 0){
        strcpy(result, word_1);
        strcat(result, word_2);
    }  
    else{
        strcpy(result, word_2);
        strcat(result, word_1);
    }
    printf("%s", result);

    for(int i = 0; i <a_word_count; i++){
        free(word_a[i]);
    }
    for(int i = 0; i < b_word_count; i++){
        free(word_b[i]);
    }
    
    free(word_a);
    free(word_b);


    return 0;
}


/*
 4
book desk pencil paper
orange apple banana lemon grape
*/