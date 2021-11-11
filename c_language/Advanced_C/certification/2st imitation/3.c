#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, len;
    char **strs;
    char *str, *p, cmp[101];

    scanf("%d", &n);
    getchar();
    gets(cmp);

    strs = (char **) malloc (sizeof(char *) * n);
    if(strs == NULL){
        return -1;
    }

    for(int i = 0; i < n; i++){
        gets(str);
        len = strlen(str);
        strs[i] = (char *)malloc(sizeof(char) * len);
        strcpy(strs[i], str);
    }

    for(p = strs; p < strs + n; p++){

    }



    return 0;
}