#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct reserve{ 
    int id; // 고객 id
    char grade[4]; // 구매한 티켓의 등급
    int price; // 구매한 티켓의 가격
};

struct tot_price{
    int id; // 고객 id
    int total_price; // 티켓 구매에 사용한 총 금액
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

int cal_num(struct reserve *p, int N){
    int count = 0;
    int *id, *p_id, *p_id_j;
    int id_index = 0;
    struct reserve *p_i, *p_j;

    id = (int *) malloc(sizeof(int) * N);

    for(p_i = p; p_i < p + N; p_i++){
        *(id + id_index) = p_i->id;
        id_index++;
    }
    for(p_id = id; p_id < id + id_index - 1; p_id++){
        for(p_id_j = p_id + 1; p_id_j < id + id_index; p_id_j++){
            if(*p_id == *p_id_j){
                *p_id_j =  -1;
            }
        }
    }

    for(p_id = id; p_id < id + id_index; p_id++){
        if(*p_id != -1){
            count++;
        }
    }

    free(id);
    
    return count;
}

void cal_sum(struct reserve *p, int N, struct tot_price *q){
    struct reserve *p_i;
    int *id, *p_id, *p_id_j;
    int id_index = 0, tot_index = 0;
    int total = 0;
    

    id = (int *) malloc(sizeof(int) * N);

    for(p_i = p; p_i < p + N; p_i++){
        *(id + id_index) = p_i->id;
        id_index++;
    }
    for(p_id = id; p_id < id + id_index - 1; p_id++){
        for(p_id_j = p_id + 1; p_id_j < id + id_index; p_id_j++){
            if(*p_id == *p_id_j){
                *p_id_j =  -1;
            }
        }
    }
    for(p_id = id; p_id < id + id_index; p_id++){
        if(*p_id != -1){
            total = 0;
            for(p_i = p; p_i < p + N; p_i++) {
                if(*p_id == p_i->id){
                    total += p_i->price;
                }
            }
            (q + tot_index)->id = *p_id;
            (q + tot_index)->total_price = total;
            tot_index++;
        }
    }
    free(id);
}

int main(){
    struct reserve *list;
    struct tot_price *result;
    int n, customer;

    scanf("%d", &n);

    list = (struct reserve *)malloc(sizeof(struct reserve) * n);
    if(list == NULL){
        return -1;
    }

    input(list, n);
    customer = cal_num(list, n);

    result = (struct tot_price *)malloc(sizeof(struct tot_price) * customer);

    cal_sum(list, n, result);

    for(int i = 0; i < customer; i++){
        printf("%d %d\n", result[i].id, result[i].total_price);
    }

    free(list);
    free(result); 

    return 0;
}