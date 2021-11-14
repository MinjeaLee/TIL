#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char *studentName; // 학생 이름
    char id[5]; // 학생 학번
    char *subjectName; // 과목 이름
    double subjectScore; // 과목 점수
}stu;

int main(){
    stu *list, *p, tmp;
    int n, k, len_name, len_subject;
    char name_tmp[95], subject_tmp[95];

    scanf("%d", &n);
    getchar();

    list = (stu *)malloc(sizeof(stu) * n);
    for(p = list; p < list + n; p++){
        scanf("%s %s %s %lf", name_tmp, p->id, subject_tmp, &p->subjectScore);
        getchar();
        len_name = strlen(name_tmp);
        len_subject = strlen(subject_tmp);
        p->studentName = (char *)malloc(sizeof(char) * len_name + 1);
        p->subjectName = (char *)malloc(sizeof(char) * len_subject + 1);

        strcpy(p->studentName, name_tmp);
        strcpy(p->subjectName, subject_tmp);
    }

    scanf("%d", &k);

    for(int i = 0; i < n - 1; i++){
        for(p = list; p < list + n - 1 - i; p++){
            if(p->subjectScore < (p + 1)->subjectScore){
                tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }
    
    printf("%s %s %s %.2lf", (list + k - 1)->studentName, (list + k - 1)->id, (list + k - 1)->subjectName, (list + k -1)->subjectScore);

    for(int i = 0; i < n; i++){
        free(list[i].studentName);
        free(list[i].subjectName);
    }
    free(list);


    return 0;
}