#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct subject{
    char *name;
    double score;
}sub;

typedef struct student{
    char *name;
    char id[5];
    int numSubject;
    sub *psub;
    double avg;
}stu;

int main(){
    stu *list, *p, tmp;
    sub sub_tmp, *p_sub;
    int n, k, blank_count;
    int sub_num,len_sub_name = 0;
    char str[101], *p_str;


    char words[50][50];
    int index_1d = 0, index_2d = 0;
    double sc, total = 0;
    
    
    scanf("%d", &n);
    getchar();

    list = (stu *)malloc(sizeof(stu) * n);

    for(p = list; p < list + n; p++){
        gets(str);
        for(p_str = str; *p_str != '\0'; p_str++){
            if(*p_str != ' '){
                words[index_1d][index_2d] = *p_str;
                index_2d++;
            }
            else{
                words[index_1d][index_2d] = '\0';
                index_2d = 0;
                index_1d++;
            }
        }
        words[index_1d][index_2d] = '\0';
        sub_num = (index_1d - 2) / 2;
        p->numSubject = sub_num;
        p->psub = (sub *)malloc(sizeof(sub) * sub_num);
        total = 0;
        for(int i = 0; i < index_1d; i++){
            if(i == 0){ // name
                len_name = strlen(words[i]);
                p->name = (char*)malloc(sizeof(char) * len_name + 1);
                strcpy(p->name, words[i]);
            }
            else if(i == 1){    // id
                strcpy(p->id, words[i]);
            }
            else if(i % 2 == 0){ // 
                len_sub_name = strlen(words[i]);
                p->psub->name = (char *) malloc (sizeof(char) * len_sub_name + 1);
                strcpy(p->psub->name, words[i]);
            }
            else{
                sc = atof(words[i]);
                p->psub->score = sc;
                total += sc;
            }
        }
        p->avg = total / sub_num;
    }
    scanf("%d", &k);

    for(int i = 0; i < n - 1; i++){
        for(p = list; p < list + n - 1 - i; p++){
            if(p->avg < (p + 1)->avg){
                tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }

    for(int i = 0; i < (list + k - 1)->numSubject - 1; i++){
        for(p_sub = (list + k - 1)->psub; p_sub < (list + k - 1)->psub + (list + k - 1)->numSubject - 1 - i; p_sub++){
            if(p_sub->score < (p_sub + 1)->score){
                sub_tmp = *p_sub;
                *p_sub = *(p_sub + 1);
                *(p_sub + 1) = sub_tmp;
            }
        }
    }


    printf("%s %s %.2lf %s %.2lf", (list + k - 1)->name, (list + k - 1)->id, (list + k - 1)->avg, (list + k - 1)->psub->name, (list + k - 1)->psub->score);
    

    return 0;
}
