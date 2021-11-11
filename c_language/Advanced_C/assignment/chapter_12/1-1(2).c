#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _st{
    char *str;
    int cnt_cons, cnt_vowel;
}st;

int main(){
    st *list, *p_i, *p_j, tmp;
    int n, len, count_vowel;
    char str_tmp[101];
    char vowel[10] = {'A', 'a', 'E', 'e', 'i', 'o', 'u', 'I', 'O', 'U'};

    scanf("%d", &n);
    getchar();

    list = (st *)malloc(sizeof(st) * n);
    if(list == NULL){
        return 0;
    }
    // 확인
    for(p_i = list; p_i < list + n; p_i++){
        scanf("%s", str_tmp);
        getchar();

        len = strlen(str_tmp);
        p_i->str =  ( char * )malloc(sizeof(char) * len + 1);
        if(p_i->str == NULL){
            return 0;
        }
        // 확인
        strcpy(p_i->str, str_tmp);
    }

    for(p_i = list; p_i < list + n; p_i++){
        count_vowel = 0;
        for(int i = 0; i < strlen(p_i->str); i++) {
            for(int j = 0; j < 10; j++){
                if(p_i->str[i] == vowel[j]) {
                    count_vowel++;
                    break;
                }
            }
        }
        p_i->cnt_vowel = count_vowel;
        p_i->cnt_cons = strlen(p_i->str) - count_vowel;
    }

    for(int i = 0; i < n - 1; i++){
        for(p_i = list; p_i < list + n - i - 1; p_i++){
            if(p_i->cnt_cons < (p_i + 1)->cnt_cons){
                tmp = *p_i;
                *p_i = *(p_i + 1);
                *(p_i + 1) = tmp;
            }
            else if(p_i->cnt_cons == (p_i + 1)->cnt_cons){
                if(p_i->cnt_vowel < (p_i + 1)->cnt_vowel){
                    tmp = *p_i;
                    *(p_i) = *(p_i + 1);
                    *(p_i + 1) = tmp;
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