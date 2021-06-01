#include <stdio.h>



// int main(){
//     double a;
//     a = (10 + 20 + 230 + 40 + 54) / 5.0;
//     printf("%lf", a);
//     return 0;
// /

int a, b;

int swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 1, b = 2;
    int *pa, *pb;
    pa = &a;
    pb = &b;

    swap(pa, pb);
    printf("%d %d", *pa, *pb);

}