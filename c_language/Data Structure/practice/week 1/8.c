#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char name[8];
    int kor;
    int eng;
    int math;
    double avg;

}stu;

int main(){
    int n;
    
    scanf("%d", &n);

    stu* students = (stu*)malloc(sizeof(stu) * n);

    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].math);
        students[i].avg = (double)(students[i].kor + students[i].eng + students[i].math) / 3;
    }

    for(int i = 0; i < n; i++){
        printf("%s %.1lf ", students[i].name, students[i].avg);
        if(students[i].math >= 90 || students[i].kor >= 90 || students[i].eng >= 90){
            printf("GREAT ");
        }
        if(students[i].math < 70 || students[i].kor < 70 || students[i].eng < 70){
            printf("BAD");
        }
        printf("\n");
    }

    free(students);


    return 0;
}