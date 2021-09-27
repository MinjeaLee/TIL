#include <stdio.h>
#include <math.h>
#include <string.h>

void append(char *dst, char c) {
    char *p = dst;
    while (*p != '\0') p++; // 문자열 끝 탐색
    *p = c;
    *(p+1) = '\0'; 
}
char* strrev_1(char* str){
    int startIdx, endIdx;
    if(!str || !*str)    return (char *)-1;
    startIdx = 0;
    endIdx = strlen(str)-1;
    while(startIdx<endIdx) {
        char tmp = str[startIdx];
        str[startIdx] = str[endIdx];
        str[endIdx] = tmp;
        startIdx ++;
        endIdx --;
    }
    return str;
} 

int main(){
    int n, num, extra;
    char print_num[2048], tmp;


    scanf("%d", &n);
    num = pow(n, 2);
    extra = num / 9;
    num += extra;
    print_num[0] = '\0';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int j = 0; j < 2 * i + 1; j++){
            if(num % 10 == 0){
                num--;
            }
            tmp = (num % 10) + '0';
            append(print_num, tmp);
            num--;
        }
        printf("%s", strrev_1(print_num));
        if(i != n -1){
            printf("\n");
        }
        print_num[0] = '\0';
    }

    return 0;
}