#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct taxi_info{
    char start[11];
    char target[11];
    double distance;
    int t_time;
    char late_night;
    int tot;

}TAXI;

int main(){
    TAXI list[20];
    int n;
    int total;
    int pay;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%s %s %lf %d %c", list[i].start, list[i].target, &list[i].distance, &list[i].t_time, &list[i].late_night);
        getchar();

        total = 0;

        if(list[i].late_night == 'N'){
            total += 3800;

            pay = (list[i].distance - 2) * 1000 / 100;
            pay *= 100;
            total += pay;

            pay = list[i].t_time / 30;
            pay *= 100;
            total += pay;

        }
        else{
            total += 4800;

            pay = (list[i].distance - 2) * 1000 / 100;
            pay *= 120;
            total += pay;

            pay = list[i].t_time / 30;
            pay *= 120;
            total += pay;
        }
        list[i].tot = total;
    }

    for(int i = 0; i < n; i++){
        printf("%s %s %d\n", list[i].start, list[i].target, list[i].tot);
    }


    return 0;
}


// /*
// 4 
// aaa bbb 2 180 N
// ccc ddd 2.25 135 Y
// eee fff 5 0 Y
// ggg hhh 7.5 60 N 
// */