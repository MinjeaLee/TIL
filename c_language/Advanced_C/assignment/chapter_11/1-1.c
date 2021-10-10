#include <stdio.h>
#include <string.h>

typedef struct sutduent{

    char name[10], grade;
    int id;

}stu;

int main(){

    stu chart[5];
    char check_name[10];

    for(int i = 0; i < 5; i++){
        scanf("%s %d %c", &chart[i].name, &chart[i].id, &chart[i].grade);
        getchar();
    }
    scanf("%s", check_name);

    for(int i = 0; i < 5; i++){
        if(strcmp(check_name, chart[i].name) == 0){
            printf(" %d %c", chart[i].id, chart[i].grade);
        }
    }

    return 0;
}