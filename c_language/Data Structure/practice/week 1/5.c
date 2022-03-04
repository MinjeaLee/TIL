#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// input two times (ex. 10 20 30\n12 05 10), output two times difference (ex. 1 44 40)
typedef struct _time{
    int hour, min, sec
}time;


int main(){
    time t1, t2;
    int hour_diff, min_diff, sec_diff;

    scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
    scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

    hour_diff = t2.hour - t1.hour;
    min_diff = t2.min - t1.min;
    sec_diff = t2.sec - t1.sec;

    if(sec_diff < 0){
        sec_diff += 60;
        min_diff--;
    }
    if(min_diff < 0){
        min_diff += 60;
        hour_diff--;
    }

    printf("%d %d %d", hour_diff, min_diff, sec_diff);

    return 0;
}