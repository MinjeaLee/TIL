#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **word_a, **word_b, **result;  // 단어 담을 포인터 배열 a,b 결과 저장 배열 선언
    char str_a[101], str_b[101], *p_i, *tmp;        // 문자열 a b 포인터, 스왑시 tmp 선언
    int count_word_a = 0, len_word_a = 0, index_word_a = 0;     // a 배열의 인덱스 값, 단어 길이, 단어 갯수 변수 선언
    int count_word_b = 0, len_word_b = 0, index_word_b = 0; // a 와 동일
    int index_1d = 0, index_2d = 0;  // 이차원 배열의 인덱스 값 저장

    int same_count = 0;     // 같은 단어 갯수 저장 변수


    gets(str_a);        // 문자열 입력
    gets(str_b);

    // str_a의 경우 이고 str_b도 이와 완전히 동일함으로 주석 생략
    for(p_i = str_a; p_i < str_a + strlen(str_a); p_i++){      
        if(*p_i == ' '){
            count_word_a++;     // 공백시 단어 개수 ++
        }
    }   
    count_word_a++; // 마지막 단어의 경우 안세짐으로 ++

    word_a = (char ** ) malloc(sizeof(char *) * count_word_a);  // 단어 갯수 만큼 할당
    if(word_a == NULL){     // 할당 확인
        return -1;
    }
    for(p_i = str_a; p_i < str_a + strlen(str_a); p_i++){ // 문자열 검색
        if(*p_i != ' '){    // 공백 이전까지 던어 길이 ++
            len_word_a++;
        }
        else{
            word_a[index_word_a] = (char *) malloc(sizeof(char) * len_word_a + 1); // 단어 길이만큼 할당
            if(word_a[index_word_a] == NULL){       // 확인
                return -1;
            }
            len_word_a = 0;         // 단어길이 초기화
            index_word_a++;         // 저장 인덱스 ++
        }
    }
    word_a[index_word_a] = (char *) malloc(sizeof(char) * len_word_a + 1);  // 마지막 단어의 경우 할당되지 않으므로 할당
    if(word_a[index_word_a] == NULL){ // 확인
        return -1;
    }

    for(p_i = str_a; p_i < str_a + strlen(str_a); p_i++){       // 문자열 검색
        if(*p_i != ' '){        // 공백이 아닌경우
            word_a[index_1d][index_2d] = *p_i;  // 저장
            index_2d++;                 // 인덱스 ++
        }
        else{
            word_a[index_1d][index_2d] = '\0';  // 공백의 경우 마지막 널문자 삽입
            index_1d++;                         // 1차원 인덱스 ++
            index_2d = 0;                       // 2차원 인덱스 초기화
        }
    }
    word_a[index_1d][index_2d] = '\0';          // 마지막의 경우 안되므로 널문자 삽입
    index_1d = 0;                               // str_b에서 쓰이므로 초기화
    index_2d = 0;

    // str_b
    for(p_i = str_b; p_i < str_b + strlen(str_b); p_i++){
        if(*p_i == ' '){
            count_word_b++;
        }
    }
    count_word_b++;

    word_b = (char ** ) malloc(sizeof(char *) * count_word_b);
    if(word_b == NULL){
        return -1;
    }
    for(p_i = str_b; p_i < str_b + strlen(str_b); p_i++){
        if(*p_i != ' '){
            len_word_b++;
        }
        else{
            word_b[index_word_b] = (char *) malloc(sizeof(char) * len_word_b + 1);
            if(word_b[index_word_b] == NULL){
                return -1;
            }
            len_word_b = 0;
            index_word_b++;
        }
    }
    word_b[index_word_b] = (char *) malloc(sizeof(char) * len_word_b + 1);
    if(word_b[index_word_b] == NULL){
        return -1;
    }

    for(p_i = str_b; p_i < str_b + strlen(str_b); p_i++){
        if(*p_i != ' '){
            word_b[index_1d][index_2d] = *p_i;
            index_2d++;
        }
        else{
            word_b[index_1d][index_2d] = '\0';
            index_1d++;
            index_2d = 0;
        }
    }
    word_b[index_1d][index_2d] = '\0';


    result = (char ** ) malloc(sizeof(char *));         // realloc을 쓰기위해 우선적으로 초기화, 같은 단어 1개 있으므로
    if(result == NULL){     // 할당 확인
        return -1;
    }

    for(int i = 0; i < count_word_a; i++){      // 같은 단어 검색, a문자열 단어 만큼 반복
        for(int j = 0; j < count_word_b; j++){                      // b단어 만큼 반복
            if(strcmp(word_a[i], word_b[j]) == 0){          // 단어 비교, 단어 같다면
                result = realloc(result, sizeof(char *) * same_count + 1);      // 새롭게 할당, 크기 늘림
                if(result == NULL){         // 확인
                    return -1;
                }
                result[same_count] = (char *) malloc(sizeof(char) * strlen(word_a[i]));     // 단어 길이만큼 할당
                if(result[same_count] == NULL){     // 확인
                    return -1;
                }
                strcpy(result[same_count], word_a[i]);      // 단어 저장
                same_count++;       // 같은 단어 개수 ++
                break;
            }
        }
    }

    for(int i = 0; i < same_count - 1; i++){            // 정렬, -> 버블 정렬 사용
        for(int j = 0; j < same_count - 1 - i; j++){
            if(strlen(result[j]) < strlen(result[j + 1])){      // 뒤의 단어가 더 긴경우
                tmp = result[j];            // 스왑
                result[j] = result[j+1];
                result[j+1] = tmp;
            }
            else if (strlen(result[j]) == strlen(result[j + 1])){       // 길이가 같은 경우
                if(strcmp(result[j], result[j + 1]) > 0){           // 사전순 비교
                    tmp = result[j];        // 스왑
                    result[j] = result[j+1];
                    result[j+1] = tmp;
                }
            }
        }
    }

    for(int i = 0; i < same_count; i++){        // 결과 출력
        printf("%s\n", result[i]);
    }
    for(int i = 0; i < count_word_a; i++){      // 메모리 반환
        free(word_a[i]);
    }
    for(int i = 0; i < count_word_b; i++){      // 메모리 반환
        free(word_b[i]);
    }
    for(int i = 0; i < same_count; i++){        // 메모리 반환
        free(result[i]);
    }
    free(word_a);       //메모리 반환
    free(word_b);
    free(result);

    return 0;
}