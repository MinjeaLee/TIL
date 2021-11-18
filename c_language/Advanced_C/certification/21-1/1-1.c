#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
    char name[21];
    int first;
    int second;
    double avg;
}stu;

void insertData(stu *list, int N){
    stu *p;


    for(p = list; p < list + N; p++){
        scanf("%s %d %d", p->name, &p->first, &p->second);
        getchar();
        p->avg = p->first * 0.4 + p->second * 0.6;
    }
}

void printResult(stu *list, int N, int N1, int N2){
    stu *p;

    for(p = list; p < list + N; p++){
        if(p->first <= N1 || p->second <= N2){
            printf("%s %d %d %.2lf\n", p->name, p->first, p->second, p->avg);
        }
    }
}


int main(){
    stu list[100], *p;
    int n, first_cut, second_cut;

    scanf("%d %d %d", &n, &first_cut, &second_cut);
    getchar();
    insertData(list, n);

    printResult(list, n, first_cut, second_cut);

    return 0;
}

/* 
6 60 50
Kim 80 46
Choi 76 98
Park 64 89
Chung 87 100
Lee 40 28
Kang 65 77
*/