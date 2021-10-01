#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *check(char *str, int n){
    char num_char[3], result[41], check_string[21];
    int num_int;
    char *p_str, *p_result, *p_final;

    p_result = result;
    strcpy(check_string, str);
    for(p_str = check_string; *p_str != '\0'; p_str++, p_result++){
        if('A' <= *p_str && *p_str <= 'Z'){
            *p_str += n;
            *p_result = *p_str;
        }
        else if('a' <= *p_str && *p_str <= 'z'){
            *p_str -= n;
            *p_result = *p_str;
        }
        
        else if('0' <= *p_str && *p_str <= '9'){
            if('0' <= *(p_str + 1)&& *(p_str + 1)<= '9'){     // p_str++ ÇØÁà¾ß ÇÔ
                num_char[0] = *p_str;
                num_char[1] = *(p_str+1);
                num_char[2] = '\0';
                p_str++;
            }
            else{
                num_char[0] = *p_str;
                num_char[1] = '\0';
            }
            num_int = atoi(num_char);
            for(int i = 0; i < n; i++, p_result++){
                *p_result = 'A' + num_int - 1;
            }
            p_result--;
        }
        else{
            *p_result = ' ';
        }
    }
    *(p_result + 1) = '\0';

    p_final = result;

    return p_final;
}

int main(){
    char x[21], y[21];
    int equal_check = 0, check_xy = 0;
    char *cmp;

    gets(x);
    gets(y);

    for(int i = 1; i <= 10; i++){
        cmp = check(x, i);
        if(strcmp(y, cmp) == 0){
            equal_check++;
            check_xy = 1;
            break;
        }
    }
    
    for(int i = 1; i <= 10; i++){
        cmp = check(y, i);
        if(strcmp(x, cmp) == 0){
            equal_check++;
            check_xy = 2;
            break;
        }
    }

    if(equal_check == 0){
        printf("0");
    }
    else{
        if(check_xy == 1){
            printf("1");
        }
        else{
            printf("2");
        }
    }
    

    return 0;
}