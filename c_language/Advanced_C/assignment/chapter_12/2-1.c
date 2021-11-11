#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char **words;
    char str[101], *p_i, *tmp;
    int count_word = 0, word_len = 0, word_index = 0;
    int word_index_1d = 0, word_index_2d = 0;

    gets(str);

    for(p_i = str; p_i < str + strlen(str); p_i++){
        if(*p_i == ' '){ 
            count_word++;
        }
    }

    words = (char **) malloc(count_word * sizeof(char *) + 1);

    for(p_i = str; p_i < str + strlen(str); p_i++){  
        if(*p_i != ' '){
            word_len++;
        }
        else{
            words[word_index] = (char *) malloc(word_len * sizeof(char) + 1);
            word_len = 0;
            word_index++;
        }
    }
    words[word_index] = (char *) malloc(word_len * sizeof(char) + 1);

    for(p_i = str; p_i < str + strlen(str); p_i++){
        if(*p_i != ' '){
            words[word_index_1d][word_index_2d] = *p_i;
            word_index_2d++;
        }
        else{
            words[word_index_1d][word_index_2d] = '\0';
            word_index_1d++;
            word_index_2d = 0;
        }
    }
    words[word_index_1d][word_index_2d] = '\0';

    count_word++;

    for(int i = 0; i < count_word - 1; i++){
        for(int j = 0; j < count_word - 1 - i; j++) {
            if(strlen(words[j]) < strlen(words[j + 1])){
                tmp = words[j];
                words[j] = words[j+1];
                words[j+1] = tmp;
            }
            else if (strlen(words[j]) == strlen(words[j + 1])){
                if(strcmp(words[j], words[j + 1]) > 0){
                    tmp = words[j];
                    words[j] = words[j+1];
                    words[j+1] = tmp;
                }
            }
        }
    }

    for(int i = 0; i < count_word; i++){
        printf("%s\n", words[i]);
    }

    for(int i = 0; i < count_word; i++){
        free(words[i]);
    }
    free(words);

    return 0;
}