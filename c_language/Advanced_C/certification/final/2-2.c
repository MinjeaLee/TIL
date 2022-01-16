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

TAXI *sel_max(TAXI *p, int N, char *s, char *d){
    TAXI *p_i, *result;
    int maxtot = -1;

    for(p_i = p; p_i < p + N; p_i++){
        if(strcmp(s, p_i->start) == 0 && strcmp(d, p_i->target) == 0){
            if(maxtot < p_i->tot){
                maxtot = p_i->tot;
                result = p_i;
            }
        }
    }  
    retu 
    
    
}

int main(){
    TAXI list[20], result;
    char check_1[21], check_2[21];
    int n;
    int total;
    int pay;
    
    scanf("%d" , &n);
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
    scanf("%s %s", check_1, check_2);

    result = sel_max(list, n, check_1, check_2);
    printf("")

    return 0;
}