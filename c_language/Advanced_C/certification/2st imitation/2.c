#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex{
    double real, imag;
    double abs;
}cmp;

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3){
    cmp max, min;
    double max_abs = -1, min_abs = 999999999;


    p1->abs = sqrt(p1->real * p1->real + p1->imag * p1->imag);
    p2->abs = sqrt(p2->real * p2->real + p2->imag * p2->imag);
    p3->abs = sqrt(p3->real * p3->real + p3->imag * p3->imag);

    if(p1->abs < min_abs){
        min_abs = p1->abs;
        min = *p1;
    }
    if(p2->abs < min_abs){
        min_abs = p2->abs;
        min = *p2;
    }
    if(p3->abs < min_abs){
        min_abs = p3->abs;
        min = *p3;
    }
    if(p1->abs > max_abs){
        max_abs = p1->abs;
        max = *p1;
    }
    if(p2->abs > max_abs){
        max_abs = p2->abs;
        max = *p2;
    }
    if(p3->abs > max_abs){
        max_abs = p3->abs;
        max = *p3;
    }

    *p1 = max;
    *p2 = min;
}

cmp add(cmp p1, cmp p2){
    cmp result;

    result.real = p1.real + p2.real;
    result.imag = p1.imag + p2.imag;

    return result;
}

cmp sub(cmp p1, cmp p2){
    cmp result;

    result.real = p1.real - p2.real;
    result.imag = p1.imag - p2.imag;

    return result;
}


int main(){
    cmp x, y, z, add_result, sub_result;

    scanf("%lf %lf", &x.real, &x.imag);
    scanf("%lf %lf", &y.real, &y.imag);
    scanf("%lf %lf", &z.real, &z.imag);

    abs_val(&x, &y, &z);

    add_result = add(x, y);
    sub_result = sub(x, y);

    printf("%.1lf%+.1lfi\n", add_result.real, add_result.imag);
    printf("%.1lf%+.1lfi", sub_result.real, sub_result.imag);

    return 0;
}