#include <stdio.h>

void stack1(){
    int x = 10;
    stack2();
}

void stack2(){
    int y = 100;
}

void main(){
    stack1();

    return 0;
}

