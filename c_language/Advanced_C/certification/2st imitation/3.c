#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, max_same_count = -1, same_count = 0, max_same_index = 0;
    char cmp_word[101], tmp_str[101], *p;
    char **str;

    scanf("%d %s", &n, cmp_word);
    getchar();

    str = (char **) malloc(sizeof(char *) * n);

    if(str == NULL){
        printf("ERROR\n");
        return -1;
    }

    for(int i = 0; i < n; i++){
        gets(tmp_str);
        str[i] = (char *)malloc(sizeof(char) * strlen(tmp_str) + 1);
        strcpy(str[i], tmp_str);
    }

    for(int i = 0; i < n; i++){
        same_count = 0;
        for(int j = 0; j <= strlen(str[i]) - strlen(cmp_word);){
            if(strncmp(str[i] + j, cmp_word, strlen(cmp_word)) == 0){
                same_count++;
                j+= strlen(cmp_word);
            }
            else{
                j++;
            }
        }
        if(same_count > max_same_count){
            max_same_count = same_count;
            max_same_index = i;
        }
    }

    if(max_same_count == 0){
        printf("NONE");
    }
    else{
        printf("%s", str[max_same_index]);
    }

    for(int i = 0; i < n; i++){
        free(str[i]);
    }
    free(str);

    return 0;
}