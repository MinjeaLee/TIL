#include <stdio.h>

int main(){
    char str[20];
    char str_2[5];

    for(int i = 0; i < 20 - 5 + 1; i++){
        str[i + 0] == str_2[i % 5 + 0];
        str[i + 1] == str_2[i % 5 + 1];
        str[i + 2] == str_2[i % 5 + 2];
        str[i + 3] == str_2[i % 5 + 3];
        str[i + 4] == str_2[i % 5 + 4];

    }
    
    return 0;
}