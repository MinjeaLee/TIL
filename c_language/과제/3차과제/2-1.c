#include <stdio.h>

int main(){
    int n1, n2, i, j, k, max_n, max_c, c;
    // 숫자 1, 2, for 문 변수 i, j, k, 약수가 가장 많은 수를 저장할 변수 max_n, 약수가 가장 많은 수의 약수의 개수를 저장할 변수 amx_c, 각수의 약수의 개수 저장 변수 c선언. 
    scanf("%d %d", &n1, &n2);
    // 숫자 1,2 입력
    max_n = n1; // 임시로 max_n 을 1번 숫자로 저장
    max_c = 0;  // 약수의 개수를 임시로 0의로 저장.
    for(i = n1; i <= n2; i++){  // ㅜ1 부터 n2까지의 수를 차례대로 i.
        c = 0;  // 약수개수를 0으로 초기화
        for(j = 1; j <= i; j++){    // 1부터 i까지의 수를 차례대로 j.
            if(i % j == 0){         // i를 1부터 자기자신으로 나누었을때 나머지가 0일때 약수개수 +1
                c++;
            }
        }
        if(max_c < c){ // 이전까지의 약수의 개수의 최댓값이 현재의 약수개수보다 작다면
            max_c = c;  // max_c를 현재의 c로 재 저장
            max_n = i;  // 그떄의 i를 최대약수개수의 수로 저장
        }
    }
    printf("%d %d\n", max_n, max_c); // 결과 출력
    return 0;
}