#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct subject{
    char *name;
    double score;
}sub;

typedef struct student{
    char *name;
    char id[5];
    int numSubject;
    sub *psub;
    double avg;
}stu;

int main(){
    stu *list, *p, tmp;     // 구조체 변수, 포인터, 스왑 시의 tmp 선언
    int n, k, blank_count;     // n, k, 공백 세는 변수 선언
    int max_score_index;        // psub에서의 가장 큰 점수의 위치 찾는 변수
    char str[101], *p_str;      // 입력 문자열, 문자열 포인터 선언
    int start_index = 0, end_index = 0; // 현재 문자열의 어느 위치에 있는지 찾는 변수 선언, 
    double sub_score, total, max_score = -1;    // 점수저장, 점수 총함, 최대 점수 변수 선언
    
 
    scanf("%d", &n);            // n 입력
    getchar();                  // getchar

    list = (stu *)malloc(sizeof(stu) * n);  // 구조체 할당
    for(int i = 0; i < n; i++){     // n번 반복 정보 삽입
        gets(str);                  // 문자열 입력
        start_index = 0;            // 시작, 끝 인덱스 초기화
        end_index = 0;  
        for(;str[end_index] != '\0';end_index++){ // 끝 인덱스 ++ 하면서 공백 찾기
            if(str[end_index] == ' '){  // 공백이라면
                list[i].name = (char *)calloc((end_index - start_index + 1) ,sizeof(char)); // 공백 전의 크기 만큼 할당
                strncpy(list[i].name, str + start_index, end_index - start_index); // 시작 지점 부터 공백 전의 크기만큼 복사
                end_index ++;   // 현재 끝 인덱스 공백 이므로 ++
                start_index = end_index;    // 시작 인덱스 초기화
                break;
            }
        }
        for(;str[end_index] != '\0'; end_index++){      // 끝 인덱스 ++ 하면서 공백 찾기
            if(str[end_index] == ' '){                  // 공백이라면 id 구간
                strncpy(list[i].id, str + start_index, 4);  //  id 저장
                list[i].id[4] = '\0';           // 끝에 널문자 삽입
                end_index++;                // 현재 끝 인덱스 공백 이므로 ++
                start_index = end_index;    // 시작 인덱스 초기화
                break;
            }
        }
        blank_count = 0;        // 공백 갯수 초기화 과목 이후의 공백 갯수 /2 + 1 -> 과목 갯수
        for(;str[end_index] != '\0'; end_index++){  // 끝 인덱스 ++ 하면서 공백 찾기
            if(str[end_index] == ' '){  // 공백이라면
                blank_count++;      // 공백 갯수 ++
            }
        }
        list[i].numSubject = blank_count / 2 + 1;       // 과목 수 저장

        list[i].psub = (sub *)malloc ( sizeof(sub) * list[i].numSubject);       // 과목수 만큼 동적할당

        total = 0;                      // 총점 초기화
        for(int j = 0; j < list[i].numSubject; j++){        // 과목수만큼 반복
            for(end_index = start_index + 1; str[end_index] != '\0'; end_index++){ // 끝 인덱스 ++ 하면서 공백 찾기
                if(str[end_index] == ' '){  // 공백이라면
                    list[i].psub[j].name = (char *)malloc(sizeof(char) * (end_index - start_index) + 1); // // 공백 전의 크기 만큼 할당
                    strncpy(list[i].psub[j].name, str + start_index, end_index - start_index);  // 시작 지점 부터 공백 전의 크기만큼 복사
                    end_index ++;   //  현재 끝 인덱스 공백 이므로 ++
                    start_index = end_index;    // 시작 인덱스 초기화
                    break;
                }
            }
            sub_score = 0;  // 한 과목의 점수 초기화
            if('0' <= str[end_index] && str[end_index] <= '9'){ // 숫자가 100일 수 도 있으므로 세번 체크
                sub_score *= 10;        // 점수 * 10
                sub_score += str[end_index] - '0'; // 한자리ㅏ 숫자 INT형으로 저장
                if('0' <= str[end_index + 1] && str[end_index+ 1] <= '9'){  // 2번째 숫자 체크
                    sub_score *= 10;        // 점수 * 10
                    sub_score += str[end_index + 1] - '0';  // 한자리ㅏ 숫자 INT형으로 저장
                    if('0' <= str[end_index + 2] && str[end_index + 2] <= '9'){     // 3번째 숫자 체크
                        sub_score *= 10;        // 점수 * 10
                        sub_score += str[end_index + 2] - '0';  // 한자리ㅏ 숫자 INT형으로 저장
                        start_index++;      // 시작 인덱스 ++
                    }
                    start_index++;          // 시작 인덱스 +=
                }
                start_index++;              // 시작 인덱스 ++
            }
            list[i].psub[j].score = sub_score;  // 점수 저장
            total += sub_score;         // 총점 계산
        }
        list[i].avg = total / list[i].numSubject;       // 평균 계산
    }

    scanf("%d", &k);            // K입력

    for(int i = 0; i < n - 1; i++){     // 버블 정렬 사용
        for(p = list ; p < list + n - 1; p++){ 
            if(p->avg < (p + 1)->avg){          // 뒤의 평균이 크다면
                tmp = *p;                   // 스왑
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
            else if (p->avg == (p+1)->avg){     // 평균이 같다면
                if(strcmp(p->id, (p + 1)->id) > 0){     // ID비교
                    tmp = *p;               // 스왑
                    *p = *(p + 1);
                    *(p + 1) = tmp;
                }
            }
        }
    }
    
    for(int i = 0; i < list[k - 1].numSubject; i++){        // K 번째 학생의 가장 큰 점수 검색
        if(list[k - 1].psub[i].score > max_score){          // MAX 보다 크다면
            max_score_index = i;                            // 인덱스 저장, MAX 초기화
            max_score = list[k - 1].psub[i].score;
        }
    }

    printf("%s %s %.2lf %s %.2lf\n", list[k - 1].name, list[k - 1].id, list[k - 1].avg, list[k - 1].psub[max_score_index].name, list[k - 1].psub[max_score_index].score);

        // 결과 출력

    for(int i = 0; i < n; i++){                         // 메모리 반환
        for(int j = 0; j < list[i].numSubject; j++){
            free(list[i].psub[j].name);
        }
        free(list[i].name);
    }
    free(list);

    return 0;
}