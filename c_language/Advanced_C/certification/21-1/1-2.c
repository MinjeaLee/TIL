#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_info{

    char name[11];
    int first, second;
    double avg;


};

void insertData(struct student_info*s, int N){
    struct student_info *p;

    for(p = s; p < s + N; p++){
        scanf("%s %d %d", p->name, &p->first, &p->second);
        getchar();
        p->avg = p->first * 0.4 + p->second * 0.6;
    }
}
double getAllavg(struct student_info s[], int N){
    struct student_info *p, *max_stu;
    double total = 0, avg;
    double max_avg = -1;
    int count = 0;
    

    for(p = s; p < s + N; p++) {
        total += p->avg;
        if(max_avg < p->avg){
            max_avg = p->avg;
            max_stu = p;
        }  
    }
    avg = total / N;

    for(p = s; p < s + N; p++) {
        if(p->avg < avg){
            count++;
        }
    }

    printf("%.2lf %d\n", avg, count);
    
    return avg;
}

void printResult(struct student_info*s, int N, double avg){
    struct student_info *p;

    for(p = s; p < s + N; p++){
        if(p->avg <= avg){
            printf("%s %.2lf\n", p->name, p->avg);
        }
    }
}

int main(){
    struct student_info list[100];
    int n;
    double over_avg;
    
    scanf("%d", &n);
    getchar();
    insertData(list, n);

    over_avg = getAllavg(list, n);

    printResult(list, n, over_avg);

    return 0;
}