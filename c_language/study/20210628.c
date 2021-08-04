#include <stdio.h>

int num_digit_add(int x){
    int result = 0;
    while (x != 0)
    {
        result += x % 10;
        x /= 10;
    }
    
    return result;
}

int add_gen(int *num1, int *num2, int x[], int *p_c){
    int result;
    for(int i = *num1; i < *num2; i++){
        result = num_digit_add(i) + i;
        if( )
    }
}

int main(){
    int a, b, count = 0;

    int *p_a, *p_b, *p_count;
    int x[5000];

    scanf("%d %d", p_a, p_b);


    return 0;
}