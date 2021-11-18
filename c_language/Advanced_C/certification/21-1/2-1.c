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
    char str[101];
    int count;

    scanf("%d", &n);
    scanf("%d %d", &index_1, &index_2);
    getchar();

    for(int i = 0; i < n; i++){
        // 문자열길이 고려
        gets(str);
        if(strlen(str) >= index_2){
            count = check_u(str + index_1, str + index_2);
        }
        else{
            count = check_u(str + index_1, str + strlen(str));
        }
        if(count != 0){
            printf("%d\n", count);
        }
    }






    return 0;
}


/*

3 8 
ADVANCED C PROGRAMMING
PROGRAM
Good 
****C LANGUAGE
THIS IS STRING

*/