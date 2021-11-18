#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_u(char *p, char *q){
    char *p_i;
    int count = 0;
    for(p_i = p; p_i <= q; p_i++){
        if('A' <= *p_i && *p_i <= 'Z'){
            count++;
        }
    }

    return count;
}

int main(){
    int n, index_1, index_2;
    char str[101], result[101];
    int min_count = 100, count, max_len = -1;

    scanf("%d", &n);
    scanf("%d %d", &index_1, &index_2);
    getchar();

    for(int i = 0; i < n; i++){
        gets(str);
        if(strlen(str) > index_2){
            count = check_u(str + index_1, str + index_2);
        }
        else{
            count = check_u(str + index_1, str + strlen(str));
        }
        if(count == 0){
            continue;
        }
        if(min_count > count){
            min_count = count;
            max_len = strlen(str);
            strcpy(result, str);
        }
        else if(min_count == count){
            if(max_len <= strlen(str)){
                max_len = strlen(str);
                strcpy(result, str);
            }
        }
    }

    printf("%s", result);
    

    return 0;
}