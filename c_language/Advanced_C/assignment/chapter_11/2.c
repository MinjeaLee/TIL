#include <stdio.h>

struct _bank { 
    int id; 
    int arrival_time;
    int service_time; 
    int waiting_time;
};

void waitingtime(struct _bank guest[], int N){
    int waiting;

    for(int i = 0; i < N; i++){
        waiting = 0;
        for(int j = 0; j < i; j++){
            waiting += guest[j].service_time;
        }
        guest[i].waiting_time = waiting - guest[i].arrival_time;
    }
}
double avgtime(struct _bank guest[], int N){
    double sum = 0;
    for(int i = 0; i < N; i++){
        sum += guest[i].waiting_time;
    }
    return sum / N;
}


int main(){
    int n;
    struct _bank guest[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);
    }
    waitingtime(guest, n);

    printf("%.2lf", avgtime(guest, n));

    return 0;
}