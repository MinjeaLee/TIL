#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_u(char *p, char *q){
    char *p_i;
    int count = 0;

    for(p_i = p; p_i < q; p_i++){
        if(!('a' <= *p_i && *p_i <= 'z') && !('A' <= *p_i && *p_i <= 'Z') && *p_i != ' '){
            count++;
        }
    }

    return count;
}

int main(){
    char str[101], max_str[101];
    int count, max_count = -1;
    int n;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        gets(str);
        count = check_u(str, str + strlen(str));
        if(max_count < count){
            max_count = count;
            strcpy(max_str, str);
        }
    }
    

    printf("%s", max_str);

    return 0;
}

// /*
// 5
// 1 year is 365 days.
// How are you doing?
// **Notice**
// Winter is coming.
// 1+1=2 
// */
