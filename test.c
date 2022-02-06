// Match cards. Finding a pair that minimizes the difference between pairs.
// Differences in matched cards accumulate.
// Matching between cards with the same number is prohibited.

// input example 1
//-----------------
// 4
// 7 5
// 2 2
// 5 4
// 1 8
//-----------------
// output example 1
//-----------------
// 6
// ----------------

// input example 2
//-----------------
// 3
// 10 10
// 15 16
// 20 20
//-----------------
// output example 2
//-----------------
// 19
// ----------------

// input example 3
//-----------------
// 5
// 1 1
// 2 2
// 3 3
// 4 4
// 5 5
//-----------------
// output example 3
//-----------------
// 6
// ----------------

// input example 4
//-----------------
// 6
// 30 45
// 40 60
// 80 33
// 66 22
// 58 58
// 44 78
//-----------------
// output example 4
//-----------------
// 28
// ----------------


#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(int x[], int num_of_pair){
    int i, j, temp;
    for(i = 0; i < num_of_pair; i++){
        for(j = i + 1; j < num_of_pair; j++){
            if(*(x + i) < *(x + j)){
                temp = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = temp;
            }
        }
    }
}

int change_front_or_back(int *x, int *y){
    int y_front[3], y_back[3];
    int tmp;
    int diff_back = 0;
    int diff_front = 0;
    int result;

    for(int i = 0; i < 4; i++){
        y_front[i] = *(y + i);
        y_back[i] = *(y + i);
    }

    // front_change
    tmp = y_front[0];
    y_front[0] = y_front[1];
    y_front[1] = tmp;

    // back_change
    tmp = y_back[2];
    y_back[2] = y_back[1];
    y_back[1] = tmp;

    for(int i = 0; i < 4; i++){
        diff_front += abs(x[i] - y_front[i]);
        diff_back += abs(x[i] - y_back[i]);
    }    
    if(diff_front < diff_back){
        result = 1;
    }
    else{
        result = 2;
    }
    return result;
}


void same_num_pair_check(int x[], int y[], int num_of_pair){
    int i, j;
    int tmp;
    int result;

    for(i = 0; i < num_of_pair; i++){ 
        if(x[i] == y[i]){
            if(i == 0){ 
                tmp = *(y + i);
                *(y + i) = *(y + i + 1);
                *(y + i + 1) = tmp;
            }
            else if(i == num_of_pair - 1){
                tmp = *(y + i);
                *(y + i) = *(y + i - 1);
                *(y + i - 1) = tmp;
            }
            else{
                result = change_front_or_back((x + i - 1), (y + i - 1));

                if(result == 1){ // front
                    tmp = *(y + i);
                    *(y + i) = *(y + i - 1);
                    *(y + i - 1) = tmp;
                }
                else{ // back
                    tmp = *(y + i);
                    *(y + i) = *(y + i + 1);
                    *(y + i + 1) = tmp;
                }
            }
        }
    }
}


int cal_diff(int x[], int y[], int num_of_pair){
    int i, diff = 0;
    for(i = 0; i < num_of_pair; i++){
        diff += abs(*(x + i) - *(y + i));
    }
    return diff;
}


int card_matching(int x[], int y[], int num_of_pair){ 
    int result;

    sort(x, num_of_pair);
    sort(y, num_of_pair);

    for(int i = 0; i < num_of_pair; i++){
        same_num_pair_check(x, y, num_of_pair);
    }

    printf("-----------------\n");
    for(int i = 0; i < num_of_pair; i++){ 
        printf("%d %d\n", *(x + i), *(y + i));
    }

    result = cal_diff(x, y, num_of_pair);

    return result;
}


int main(){
    // FILE *fp = fopen("./data/10.in", "r");
    int num_of_pair;
    int a[50000];
    int b[50000];
    // int result[50000]; // this array is used to store the result of difference between pairs at each case.
    int result;

    int total = 0;

    scanf("%d", &num_of_pair);

    for(int i = 0; i < num_of_pair; i++){
        scanf("%d %d", (a + i), (b + i));
    }

    // result = card_matching(a, b, num_of_pair);

    // FILE *fp = fopen("./data/1.in", "r");
    // fscanf(fp, "%d", &num_of_pair);

    // for(int i = 0; i < num_of_pair; i++){
    //     fscanf(fp, "%d %d", (a + i), (b + i));
    // }

    result = card_matching(a, b, num_of_pair);

    //!char file_name[20];
    //!char num[2] = {'1', '\0'};
    //!for(int i = 0; i <= 8; i++) {
    //!    strcpy(file_name, "\0");
    //!    strcat(file_name, "./data/");
    //!    strcat(file_name, num);
    //!    strcat(file_name, ".in");
//!
    //!    printf("%s\n", file_name);
//!
    //!    FILE *fp = fopen(file_name, "r");
    //!    fscanf(fp, "%d", &num_of_pair);
    //!    for(int i = 0; i < num_of_pair; i++){
    //!        fscanf(fp, "%d %d", &a[i], &b[i]);
    //!    }
//!
    //!    total += card_matching(a, b, num_of_pair);
    //!    num[0]++;
    //!    fclose(fp);
    //!}
//!
    // fscanf(fp, "%d", &num_of_pair);
    // // scanf("%d", &num_of_pair);

    // for(int i = 0; i < num_of_pair; i++){
    //     fscanf(fp, "%d %d", &a[i], &b[i]);
    // }

    // sort(a, num_of_pair);
    // sort(b, num_of_pair);

    // for(int i = 0; i < num_of_pair; i++){
    //     same_num_pair_check(a, b, num_of_pair);
    // }

    
    // !printf("%d\n", total);
    // !// result = cal_diff(a, b, num_of_pair);
    // !int finalfile;
    // !FILE *fp = fopen("./data/10.in", "in");
    // !fscanf(fp, "%d", &num_of_pair);
    // !for(int i = 0; i < num_of_pair; i++){
    // !    fscanf(fp, "%d %d", &a[i], &b[i]);
    // !}
// !
    // !finalfile = card_matching(a, b, num_of_pair);
    // !printf("%d\n", finalfile);
// !
    // !total += finalfile;
// !
    // !printf("result = %d\n", total);

    printf("%d\n", result);

    return 0;
}