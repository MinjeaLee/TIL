#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
    char *str;
    int words;
};

int main(){
    struct string *list, tmp, *p_i;  
    int count, n, str_len;
    char tmp_str[101], *p;

    scanf("%d", &n);
    getchar();

    list = (struct string *)malloc(sizeof(struct string) * n);
    if(list == NULL){
        return -1;
    }

    for(int i = 0; i < n; i++){
        gets(tmp_str);
        count = 0;
        str_len = strlen(tmp_str);
        list[i].str = (char *)malloc(sizeof(char) * str_len + 1);
        if(list[i].str == NULL){
            return -1;
        }
        strcpy(list[i].str, tmp_str);
        for(p = tmp_str; *p != '\0'; p++){
            if(*p == ' '){
                count++;
            }
        }
        count++;
        list[i].words = count;
    }

    for(int i = 0; i < n - 1; i++){
        for(p_i = list; p_i < list + n - 1 - i; p_i++){
            if(p_i->words < (p_i + 1)->words) {
                tmp = *p_i;
                *p_i = *(p_i + 1);
                *(p_i + 1) = tmp;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("%s %d\n", list[i].str, list[i].words);
    }

    for(int i = 0; i < n; i++){
        free(list[i].str);
    }
    free(list);


    return 0;
}