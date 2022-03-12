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
    int diff;

    scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
    scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

    diff = (t2.hour - t1.hour) * 3600 + (t2.min - t1.min) * 60 + (t2.sec - t1.sec);

    printf("%d", diff);

    return 0;
}

