#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _st{         // 구조체 선언
    char *str;              // 문자열 저장
    int cnt1, cnt2;         // 자음수 저장, 모음수 저장
    int num;                // 숫자 저장
    int result1, result2;   // 결과 1, 2 저장
}st;

int main(){
    st *list, *p_i, tmp;    // 구조체 변수, 포인터, tmp 선언
    int n, len, num, cnt_vowel, num_count;  // n, 문자열 길이, 숫자, 모음 갯수, 숫자 길이 변수 선언
    char vowel[10] = {'A', 'a', 'E', 'e', 'i', 'o', 'u', 'I', 'O', 'U'};    // 모음을 확인하기위해 모든 모음 리스트로 저장
    char str_tmp[101];          // 입력받을 문자열변수 선언

    scanf("%d", &n);        // n 입력
    getchar();      

    list = (st *)malloc(sizeof(st) * n); // n개 구조체 동적할당
    if(list == NULL){               // 동적할당 안되었다면 -1반환하고 종료
        return -1;
    }

    for(p_i = list; p_i < list + n; p_i++){     // n번 반복
        scanf("%s", str_tmp);               // 문자열 입력
        getchar();          
        len = strlen(str_tmp);              // 문자열 길이 저장
        p_i->str = (char *)malloc(sizeof(char) * len + 1); // 문자열 길이 + 1 만큼 동적할당
        if(p_i->str == NULL){               // 동적할당 안되었다면 -1반환하고 종료
            return -1;
        }
        strcpy(p_i->str, str_tmp);          // 문자열을 구조체에 복사
    }
    
    for(p_i = list; p_i < list + n; p_i++){     // n번반복
        num = 0;                                // 카운트관련 변수들 초기화
        num_count = 0;
        cnt_vowel = 0;
        for(int i = 0; i < strlen(p_i->str); i++) {     // 문자열의 길이만큼 반복
            for(int j = 0; j < 10; j++){                // 모음갯수만큼 반복
                if(p_i->str[i] == vowel[j]) {           // 모음이 있다면
                    cnt_vowel++;                        // 모음갯수 ++
                }
            }
            if('0' <= p_i->str[i] && p_i->str[i] <= '9') {      // 숫자라면 
                num *= 10;                                      // 숫자가 몇의 자리인지 모르기에 기존 숫자 * 10
                num += p_i->str[i] - '0';                       // 숫자 저장
                num_count++;                                    // 숫자 갯수 ++
            }
        }
        p_i->cnt1 = strlen(p_i->str) - cnt_vowel - num_count;         // 자음 갯수는 문자열 길이 - 모음 갯수 - 숫자갯수
        p_i->cnt2 = cnt_vowel;                                      // 모음갯수 저장
        p_i->num = num;                                             // 숫자 저장
        if(p_i->cnt1 > p_i->cnt2){                                  // 조건에 따라 return1, return2 저장
            p_i->result1 = p_i->cnt1 * num;
            p_i->result2 = p_i->cnt2 * num;
        }
        else{
            p_i->result1 = p_i->cnt2 * num;
            p_i->result2 = p_i->cnt1 * num;
        }
    }

    for(int i = 0; i < n - 1; i++){                         // 정렬
        for(p_i = list; p_i < list + n - i - 1; p_i++) {    
            if(p_i->result1 < (p_i + 1)->result1){  // 뒤에 인덱스의 result1이 더 크면 스왑
                tmp = *p_i;
                *p_i = *(p_i + 1);
                *(p_i + 1) = tmp;
            }
            else if(p_i->result1 == (p_i + 1)->result1){    // result1은 같고 
                if(p_i->result2 < (p_i + 1)->result2){      // 뒤에 인덱스의 result2가 더 크면 스왑
                    tmp = *p_i;
                    *p_i = *(p_i + 1);
                    *(p_i + 1) = tmp;
                }
            }
        }
    }

    for(p_i = list; p_i < list + n; p_i++){         // 결과 순서대로 출력
        printf("%s\n", p_i->str);
    }   
    for(p_i = list; p_i < list + n; p_i++){         // 문자열 메모리 반환
        if(p_i->str != NULL){                       // null 이 아닌경우만
            free(p_i->str);                         // 문자열 메모리 반환
            p_i->str = NULL;                        // 메모리 해제
        }
    }
    if(list != NULL){                                // 구조체 메모리 반환 null이 아닌경우만
        free(list);                                  // 반환
        list = NULL;                                 // 메모리 해제
    }

    return 0;
}