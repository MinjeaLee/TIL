#include <stdio.h>
#include <string.h>

typedef struct WRORD{
    char word[21];
    int same_count;
}chart;

int main(){
    char str[201], *p;
    chart list[10];
    int word_index_1d = 0, word_index_2d = 0;

    scanf("%[^\n]s", str);

    for(p = str; *p != '\0'; p++){
        if(('a' <= *p && *p <= 'z') || ('A' <= *p && *p <= 'Z')){
            list[word_index_1d].word[word_index_2d] = *p;
            word_index_2d++;
        }
        else{
            if(p - str != strlen(str) - 1){
                if(!(('a' <= *(p + 1)&& *(p + 1)<= 'z') || ('A' <= *(p  + 1)&& *(p + 1)<= 'Z'))){
                    continue;
                }
            }
        
            list[word_index_1d].word[word_index_2d] = '\0';
            word_index_1d++;
            word_index_2d = 0;
        }
    }
    
    if(('a' <= str[strlen(str) -1] && str[strlen(str) -1] <= 'z') || ('A' <= str[strlen(str) -1] && str[strlen(str) -1] <= 'Z')){
        word_index_1d++;
    }

    for(int i = 0; i < word_index_1d + 1; i++){
        list[i].same_count = 0;
        for(int j = 0; j < word_index_1d + 1; j++){
            if(strcmp(list[i].word, list[j].word) == 0){
                list[i].same_count ++;
            }
        }
    }

    for(int i = 0; i < word_index_1d - 1; i++){
        for(int j = i + 1; j < word_index_1d; j++){
            if(strcmp(list[i].word, list[j].word) == 0){
                strcpy(list[j].word, ".");
            }
        }

    }

    for(int i = 0; i < word_index_1d; i++){
        if(strcmp(list[i].word, ".") == 0){
            continue;
        }
        printf("%s %d\n",list[i].word, list[i].same_count);
    }


    return 0;
}
