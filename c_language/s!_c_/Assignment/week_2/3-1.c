#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char x[1001], y[1001], operator;
    int result;

    scanf("%s %c %s", x, &operator, y);
    if(operator == '+'){
        result = atoi(x) + atoi(y);
    }
    else{
        
        result = atoi(x) - atoi(y);
    }

    printf("result : %d", result);

    return 0;
}