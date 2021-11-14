#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tourcity{

    char name[21];
    int fee;
    char in_out;
    char start_day[9];
    char city_name[50];
}tourcity;

int main(){
    int n;              // n
    int *count;         // 각 도시의 관장지 개수 저장 포인터 변수
    char **city;        // 도시 이름 저장 변수
    tourcity **list, result;    // 각 도시별 관장지 저장, 결과값 저장할 구조체 변수 선언

    scanf("%d", &n);        // n 입력
    getchar();

    list = (tourcity ** ) malloc(sizeof(tourcity * ) * n);  // n개 도시 동적 할당
    if(list == NULL){           // 동적할당 확인
        printf("Not Enough Memory.\n");
        return 0;
    }

    city = (char **)malloc (sizeof (char *) * n);       // 도시 개수  동적 할당
    if(city == NULL){                               // 동젇할당 확인
        printf("Not Enough Memory.\n");
        return 0;
    }
    count = (int *)malloc(sizeof(int) * n);         // 관광지 개수 받을 포인터 동적할당
    if(count == NULL){                  // 동적할당 확인
        printf("Not Enough Memory.\n");
        return 0;
    }
    for(int i = 0; i < n; i++) {            // n번 반복
        city[i] = (char *) malloc(sizeof(char) * 50);           // 도시 이름 저장할 포인터 동적 할당
        if(city[i] == NULL) {               // 동적 할당 확인
            printf("Not Enough Memory.\n");
            return 0;
        }
    }
    for(int i = 0; i < n; i++){         // 도시 이름 입력
        scanf("%s", city[i]);\
        getchar();
    }
    
    
    for(int i = 0; i < n; i++){             //  n번 반복
        scanf("%d", &count[i]);             // 관광지 개수 입력
        getchar();          
        list[i] = (tourcity *) malloc( sizeof(tourcity) * count[i]);        // 관광지 개수대로 동적할당 후 확인
        if(list[i] == NULL){
            printf("Not Enough Memory.\n");
            return 0;
        }
    }

    for(int i = 0; i < n; i++){             // 도시 개수만큼 반복
        for(int j = 0; j < count[i]; j++) {     // 관광지 개수 만큼 반복
            scanf("%s %d %c %s",list[i][j].name, &list[i][j].fee, &list[i][j].in_out, list[i][j].start_day);        // 구조체에 입력
            strcpy(list[i][j].city_name, city[i]);  // 도시 이름 저장
        }
    }

    result = list[0][0];        // 결과 값 변수 0번째 값으로 초기화

    for(int i = 0; i < n; i++){         // 도시 개수만큼 반복
        for(int j = 0; j < count[i]; j++) {     // 관광지 개수 만큼 반복
            if(list[i][j].fee > result.fee){        // 요금 비교
                result = list[i][j];            // 결과값 변동 
            }
            else if(list[i][j].fee == result.fee){  // 요금이 같은 경우
                if(strcmp(list[i][j].start_day,result.start_day) < 0){
                    result = list[i][j];            // 시작 날짜 비교 후 결과값 변동
                }
            }
        }
    }


    printf("%s %s %d %s %c\n", result.city_name, result.name, result.fee, result.start_day, result.in_out);
                //결과 출력



    for(int i = 0; i < n; i++){
        free(city[i]);          // 도시 이름 저장 포인터 메모리 반환
        free(list[i]);          // 관광지 저장 구조체 포인터 메모리 반환
    }
    free(list);             // 구조체 메모리 반환
    free(city);             // 도시 메모리 반환
    free(count);            // 관광지 개수 저장 포인터 메모리 반환

    return 0;
}