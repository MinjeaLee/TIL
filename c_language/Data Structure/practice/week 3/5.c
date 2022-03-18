#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// towers of hanoi print all steps useing recursion
void towers(int n, char from, char to, char aux){
    if(n == 1){
        printf("%c %c\n", from, to);
    }
    else{
        towers(n - 1, from, aux, to);
        printf("%c %c\n", from, to);
        towers(n - 1, aux, to, from);
    }
}


int main(){
    int n;

    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');

    return 0;
}