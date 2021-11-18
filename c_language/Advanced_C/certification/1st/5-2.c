#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char *name;
    int kor, eng, math;
    double avg;
}stu;

void read_data(stu *list, int n){
    stu *p;
    char name[21];
    int len_name;
    double total;

    for(p = list; p < list + n; p++){
        scanf("%s %d %d %d", name, &p->kor, &p->eng, &p->math);
        getchar();
        len_name = strlen(name);
        p->name = (char *) malloc (sizeof(char) * len_name + 1);
        strcpy(p->name, name);
        total = p->kor + p->eng + p->math;
        p->avg = total / 3;
    }
}

void sort_score(stu *list, int n){
    stu *p, tmp;

    for(int i = 0; i < n - 1; i++){
        for(p = list; p < list + n - 1 - i; p++){
            if(p->avg < (p + 1)->avg){
                tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
            else if(p->avg == (p + 1)->avg){
                if(p->kor < (p + 1)->kor){
                    tmp = *p;
                    *p = *(p + 1);
                    *(p + 1) = tmp;
                }
                else if(p->kor == (p + 1)->kor){
                    if(p->eng < (p + 1)->eng){
                        tmp = *p;
                        *p = *(p + 1);
                        *(p + 1) = tmp;
                    }
                }
            }
        }
    }
}

stu *select_out(stu *list_a, stu *list_b, int n){
    int cmp = n / 2 + 1;

    if((list_a + cmp)->avg < (list_b + cmp)->avg){
        return list_b;
    }
    else{
        return list_a;
    }
}

int main(){
    stu *list_a, *list_b, *output, *p;
    int n;

    scanf("%d", &n);
    getchar();

    list_a = (stu *)malloc(sizeof(stu) * n);
    list_b = (stu *)malloc(sizeof(stu) * n);

    read_data(list_a, n);
    read_data(list_b, n);

    sort_score(list_a, n);
    sort_score(list_b, n);

    output = select_out(list_a, list_b, n);

    for(p = output; p < output + n; p++){
        printf("%s %d %d %d %.1lf\n", p->name, p->kor, p->eng, p->math, p->avg);
    }

    for(int i = 0; i < n; i++){
        free(list_a[i].name);
    }
    for(int i = 0; i < n; i++){
        free(list_b[i].name);
    }
    free(list_a);
    free(list_b);

    return 0;
}