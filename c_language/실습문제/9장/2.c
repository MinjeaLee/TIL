#include <stdio.h>

int main(){
    char string[20], a;
    int *p_ch;

    for(p_ch = string; p_ch < string + 20; p_ch++){
        scanf("%c", p_ch);
        if(*p_ch == '\n'){
            break;
        }
    }
    
    
    printf("%s", *p_ch);



    return 0;
}