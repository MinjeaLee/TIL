#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sutduent{

    char name[10], grade;
    char id[11], year[5];
    
}stu;

int main(){
    stu chart[5], check_stu;
    char check_name[10];
    int check = 0;


    for(int i = 0; i < 5; i++){
        scanf("%s %s %c", &chart[i].name, &chart[i].id, &chart[i].grade);
        strncpy(chart[i].year, chart[i].id, 4);
        chart[i].year[4] = '\0';
        getchar();
    }
    scanf("%s", check_name);

    for(int i = 0; i < 5; i++){
        if(strcmp(check_name, chart[i].name) == 0){
            check_stu.grade = chart[i].grade;
            strcpy(check_stu.name, chart[i].name);
            strcpy(check_stu.id, chart[i].id);
            strcpy(check_stu.year, chart[i].year);
            check_stu.year[4] = '\0';
            break;
        }
    }
    

    for(int i = 0; i < 5; i++){
        if(strcmp(check_stu.year, chart[i].year) == 0 && check_stu.grade == chart[i].grade && strcmp(check_stu.name,chart[i].name) != 0){
            printf("%s ", chart[i].name);
            check = 1;
        }
    }
    if(check == 0){
        printf("0");
    }
    printf("\n");
    printf("%s %d", check_stu.year, atoi(check_stu.year) % 131);
    
    return 0;
}