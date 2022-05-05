#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int result[201];
    int tmp;
    int num = 0;

    for(;;){
        scanf("%d", &tmp);
        if(tmp == -1) break;
        result[num] = tmp;
        num++;
    }

    for(;;) {
        scanf("%d", &tmp);
        if(tmp == -1) break;
        result[num] = tmp;
        num++;
    }

    for(int i = 0; i < num - 1; i++) {
        for(int j = i + 1; j < num; j++) {
            if(result[j] > result[j + 1]) {
                tmp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tmp;
            }
        }
    }

    for(int i = 0; i < num - 1; i++) {
        if(result[i] == -1){
            continue;
        }
        for(int j = i + 1; j < num; j++) {
            if(result[i] == result[j]){
                result[j] = -1;
            }
        }
    }

    for(int i = 0; i < num; i++) {
        if(result[i] == -1){
            continue;
        }
        printf(" %d", result[i]);
    }

    return 0;
}