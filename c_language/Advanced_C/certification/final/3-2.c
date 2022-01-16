#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_w(char *p, char *q){
    int len = strlen(p);
    char *p_i;
    int count = 0;

    if(p + len < q){
        for(p_i = p; p_i < p + len; p_i++){
            if(!('a' <= *p_i && *p_i <= 'z') && !('A' <= *p_i && *p_i <= 'Z') && *p_i != ' '){
                count++;
            }
        }
    }
    else{
        for(p_i = p; p_i < q; p_i++){     
            if(!('a' <= *p_i && *p_i <= 'z') && !('A' <= *p_i && *p_i <= 'Z') && *p_i != ' '){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n, m;
    char result[10][101], str[101], tmp_str[101];
    int count[10], result_index = 0, count_str;
    int tmp_count;

    scanf("%d %d", &n, &m);
    getchar();

    for(int i = 0; i < n; i++){
        gets(str);
        count_str = check_w(str, str + m);
        if(count_str != 0){
            count[result_index] = count_str;
            strcpy(result[result_index], str);
            result_index++;
        }
    }

    for(int i = 0; i < result_index - 1; i++){
        for(int j = 0; j < result_index - 1 - i; j++){
            if(count[j] < count[j + 1]){
                tmp_count = count[j];
                count[j] = count[j+1];
                count[j + 1] = tmp_count;

                strcpy(tmp_str, result[j]);
                strcpy(result[j], result[j + 1]);
                strcpy(result[j + 1], tmp_str);
            }
        }
    }

    for(int i = 0; i < result_index; i++){
        printf("%s\n", result[i]);
    }


    return 0;
}

/*
5 15
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming 
1+1=2 
*/