#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex{
    double real, imaginary, abs;
}complex;

struct complex add(complex x, complex y){
    complex result;
    double real, imaginary;

    real = x.real + y.real;
    imaginary = x.imaginary + y.imaginary;

    result.real = real;
    result.imaginary = imaginary;

    return result;
}

struct complex sub(complex x, complex y){
    complex result;
    double real, imaginary;

    real = x.real - y.real;
    imaginary = x.imaginary - y.imaginary;

    result.real = real;
    result.imaginary = imaginary;

    return result;
}

void abs_val(complex *p1, complex *p2, complex *p3){
    complex *p, tmp;
    double cal_abs, max =  -1, min = 999999999;

    for(p = p3; p < p3 + 3; p++){
        cal_abs = sqrt(p->real * p->real + p->imaginary * p->imaginary);
        p->abs = cal_abs;
    }
    for(p = p3; p < p3 + 3; p++){
        if(p->abs < min){
            min = p->abs;
            p2 = p;
        }
        if(p->abs > max){
            max = p->abs;
            p1 = p;
        }
    }
}

int main(){
    complex list[3], *p, max, min, _add, _sub;

    for(p = list; p < list + 3; p++){
        scanf("%lf %lf", &p->real, &p-> imaginary);
    }

    abs_val(&max, &min, list);

    _add = add(max, min);
    _sub = sub(max, min);

    printf("%+.1lf%.1lf\n", _add.real, _add.imaginary);
    printf("%+.1lf%.1lf\n", _sub.real, _sub.imaginary);

    return 0;
}