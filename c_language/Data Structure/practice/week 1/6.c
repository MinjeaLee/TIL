#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Print out the name of the student who scored below average.

typedef struct student{
    char name[9];
    int score;
}stu;

int main(){
    stu list[5];
    double avg;
    int sum = 0;

    for(int i=0; i<5; i++){
        scanf("%s %d", list[i].name, &list[i].score);
        sum += list[i].score;
    }

    avg = (double)sum / 5;

    for(int i=0; i<5; i++){
        if(list[i].score < avg){
            printf("%s\n", list[i].name);
        }
    }

    return 0;
}