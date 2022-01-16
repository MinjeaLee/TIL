#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct reserve{ 
    int id; // 고객 id
    char grade[4]; // 구매한 티켓의 등급
    int price; // 구매한 티켓의 가격
};

void input(struct reserve *p, int N){
    struct reserve *p_i;

    for(p_i = p; p_i < p + N; p_i++){
        scanf("%d %s", &p_i->id, p_i->grade);

        if(strcmp(p_i->grade, "VIP") == 0){
            p_i->price = 140000;
        }
        else if(strcmp(p_i->grade, "R") == 0){
            p_i->price = 110000;
        }
        else if(strcmp(p_i->grade, "S") == 0){
            p_i->price = 85000;
        }
        else{
            p_i->price = 55000;
        }
    }
}

int cal_sum(struct reserve *p, int N, int id){
    struct reserve *p_i;
    int sum = 0;

    for(p_i = p; p_i < p + N; p_i++){
        if(p_i->id == id){
            printf("%s %d\n", p_i->grade, p_i->price);
            sum += p_i->price;
        }
    }

    return sum;
}

int main(){
    struct reserve *list;
    int n, check_id, check_sum;

    scanf("%d", &n);

    list = (struct reserve *)malloc(sizeof(struct reserve) * n);   
    if(list == NULL){
        printf("out of memory\n");
        return 1;
    }

    input(list, n);

    scanf("%d",&check_id);

    check_sum = cal_sum(list, n, check_id);
    printf("%d", check_sum);

    free(list);

    return 0;
}

// *
// 10 
// 123 A
// 210 VIP
// 123 A
// 123 R
// 210 S
// 210 VIP
// 123 A
// 523 A
// 123 R
// 523 VIP
// 123 
// */