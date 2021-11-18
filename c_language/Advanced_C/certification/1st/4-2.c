#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stock{
    char sid[7];
    int qty;
    double cost_avg;
    double total;
}stock;

void put_stock_list(stock *p, char *stock_id, int qty, double cost){
    strcpy(p->sid, stock_id);
    p->qty += qty;
    p->total += cost * qty;
    p->cost_avg = p->total/p->qty;
}

int input(stock *p, int n){
    stock *p_i;
    char tmp_sid[7];
    double tmp_cost;
    int tmp_qty;
    int same_check = 0;
    int list_index = 0;

    for(int i = 0; i < n; i++){
        scanf("%s %d %lf", tmp_sid, &tmp_qty, &tmp_cost);
        same_check = 0;
        for(p_i = p; p_i < p + list_index; p_i++) {
            if(strcmp(tmp_sid, p_i->sid) == 0){
                put_stock_list(p_i, tmp_sid, tmp_qty, tmp_cost);
                same_check = 1;
                break;
            }
        }
        if(same_check == 0){
            put_stock_list((p + list_index), tmp_sid, tmp_qty, tmp_cost);
            list_index++;
        }
    }
    return list_index;
}



void display(stock *p, int n){
    stock *p_i;

    for(p_i = p; p_i < p + n; p_i++){
        printf("%s %d %.2lf %.2lf\n", p_i->sid, p_i->qty, p_i->cost_avg, p_i->total);
    }
}


int main(){
    stock list[20] = {0,};
    int n;
    int num_stock;

    scanf("%d", &n);
    getchar();

    num_stock = input(list, n);


    display(list, num_stock);

    return 0;
}