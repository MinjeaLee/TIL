#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{

    char name[11];
    int first, second;
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
double getAllavg(stu s[], int N){
    stu *p, *max_stu;
    double total = 0, avg;
    double max_avg = -1;
    

    for(p = s; p < s + N; p++) {
        total += p->avg;
        if(max_avg < p->avg){
            max_avg = p->avg;
            max_stu = p;
        }  
    }
    avg = total / N;
    printf("%.2lf\n", avg);
    printf("first=%s %.2lf\n", max_stu->name, max_stu->avg);
    
    return avg;
}

void printResult(stu *s, int N, double avg){
    stu *p;

    for(p = s; p < s + N; p++){
        if(p->avg <= avg){
            printf("%s %.2lf\n", p->name, p->avg);
        }
    }
}

int main(){
    stu list[100];
    int n;
    double over_avg;
    
    scanf("%d", &n);
    getchar();
    insertData(list, n);

    over_avg = getAllavg(list, n);

    printResult(list, n, over_avg);

    return 0;
}