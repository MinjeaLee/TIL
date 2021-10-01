#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char str[21], num_char[3], result[1024];
    int n, num_int;
    char *p_str, *p_result;

    gets(str);
    scanf("%d", &n);
    // scanf("%s\n%d", str, &n);
    

    p_result = result;
    for(p_str = str; *p_str != '\0'; p_str++, p_result++){
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


    printf("%s", result);

    return 0;
}