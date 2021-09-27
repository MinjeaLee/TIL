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




1234567890 i < 5
23          j < 2

i = 0

    j = 0, x = 0 
    j = 1, x = 1  

i = 1
    j = 0, 2 
    j = 1, 3

i = 2
    j = 0, 4
    