#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _job{
    char *name; // 작업명 (공백 없이 최대 100자)
    char *start; // 작업 시작 시간 (HH:MM:SS; 24시간제 시간,분,초 예)15:32:35)
    char *end; // 작업 종료 시간 (위와 동일)
    int money; // 작업 대금 (수익) 
}ABC;

int main(){
    ABC *list, tmp;
    int n;
    char tmp_name[101], tmp_start[10], tmp_end[10];

    scanf("%d", &n);
    getchar();

    list = (ABC *)malloc(sizeof(ABC) * n);
    if(list == NULL){
        return -1;
    }

    for(int i = 0; i < n; i++){
        scanf("%s %s %s %d", tmp_name, tmp_start, tmp_end, &list[i].money);
        getchar();
        list[i].name = (char *)malloc(sizeof(char) * strlen(tmp_name) + 1);
        strcpy(list[i].name, tmp_name);
        list[i].start = (char *)malloc(sizeof(char) * strlen(tmp_start) + 1);
        strcpy(list[i].start, tmp_start);
        list[i].end = (char *)malloc(sizeof(char) * strlen(tmp_end) + 1);
        strcpy(list[i].end, tmp_end);
    } 

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++){
            if(strcmp(list[j].start, list[j + 1].start) > 0){
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }

    printf("%s %s %s %d", list[0].name, list[0].start, list[0].end, list[0].money);

    for(int i = 0; i < n; i++){
        free(list[i].name);
        free(list[i].start);
        free(list[i].end);
    }
    free(list);

    return 0;
}


/*
4
Remove 09:45:00 13:00:00 50
Cleaning 08:27:45 10:00:00 50
Painting 13:00:15 18:00:00 100
Checking 15:00:00 18:00:00 10
*/

/*
5
Remove 09:45:00 13:00:00 50
Cleaning 08:27:45 10:00:00 80
Painting 13:00:15 18:00:00 100
Checking 15:00:00 18:00:00 10
Preview 08:27:45 10:00:00 80 
*/