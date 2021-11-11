#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st{
    char *str;
    int cnt_vowel;
    int cnt_cons;
}word;

int main(){
    word *list, tmp, *p_i, *p_j;
    int n, len_str, vowel_count;
    char tmp_str[101];
    char vowel[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

    scanf("%d", &n);
    getchar();

    list = (word *)malloc(sizeof(word) * n);
    if(list == NULL){
        return -1;
    }

    for(p_i = list; p_i < list + n; p_i++){
        scanf("%s", tmp_str);
        getchar();
        len_str = strlen(tmp_str);
        p_i->str = (char *)malloc(sizeof(char) * len_str + 1);
        if(p_i->str == NULL){
            return -1;
        }
        strcpy(p_i->str, tmp_str);
        vowel_count = 0;
        for(int i = 0; i < len_str; i++){
            for(int j = 0; j < 10; j++){
                if(p_i->str[i] == vowel[j]){
                    vowel_count++;
                }
            }
        }
        p_i->cnt_vowel = vowel_count;
        p_i->cnt_cons = len_str - vowel_count;
    }

    for(p_i = list; p_i < list + n - 1; p_i++){
        for(p_j = p_i + 1; p_j < list + n; p_j++){
            if(p_i->cnt_cons < p_j->cnt_cons){
                tmp = *p_i;
                *p_i = *p_j;
                *p_j = tmp;
            }
            else if(p_i->cnt_cons == p_j->cnt_cons){
                if(p_j->cnt_vowel > p_i->cnt_vowel){
                    tmp = *p_i;
                    *p_i = *p_j;
                    *p_j = tmp;
                }
            }
        }
    }

    for(p_i = list; p_i < list + n; p_i++){
        printf("%s\n", p_i->str);
    }
    for(p_i = list; p_i < list + n; p_i++){
        if(p_i->str != NULL){
            free(p_i->str);
            p_i->str = NULL;
        }
    }
    if(list != NULL){
        free(list);
        list = NULL;
    }
    
    return 0;
}