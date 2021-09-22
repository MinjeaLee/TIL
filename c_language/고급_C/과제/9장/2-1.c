#include <stdio.h>
#include <limits.h>

int main(){
    int n, arr[21];
    int *p_n = &n, *p_arr;
    int count_overlap = 0;


    scanf("%d", p_n);

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        scanf("%d", p_arr);
    }
    if(n < 5){
        printf("-1");
        return 0;
    }

    

    



    return 0;
}