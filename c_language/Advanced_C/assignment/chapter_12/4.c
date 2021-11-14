#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tourcity{

    char name[21];
    int fee;
    char in_out;
    char start_day[9];
    char city_name[50];
}tourcity;

int main(){
    int n;              // n
    int *count;         // �� ������ ������ ���� ���� ������ ����
    char **city;        // ���� �̸� ���� ����
    tourcity **list, result;    // �� ���ú� ������ ����, ����� ������ ����ü ���� ����

    scanf("%d", &n);        // n �Է�
    getchar();

    list = (tourcity ** ) malloc(sizeof(tourcity * ) * n);  // n�� ���� ���� �Ҵ�
    if(list == NULL){           // �����Ҵ� Ȯ��
        printf("Not Enough Memory.\n");
        return 0;
    }

    city = (char **)malloc (sizeof (char *) * n);       // ���� ����  ���� �Ҵ�
    if(city == NULL){                               // �����Ҵ� Ȯ��
        printf("Not Enough Memory.\n");
        return 0;
    }
    count = (int *)malloc(sizeof(int) * n);         // ������ ���� ���� ������ �����Ҵ�
    if(count == NULL){                  // �����Ҵ� Ȯ��
        printf("Not Enough Memory.\n");
        return 0;
    }
    for(int i = 0; i < n; i++) {            // n�� �ݺ�
        city[i] = (char *) malloc(sizeof(char) * 50);           // ���� �̸� ������ ������ ���� �Ҵ�
        if(city[i] == NULL) {               // ���� �Ҵ� Ȯ��
            printf("Not Enough Memory.\n");
            return 0;
        }
    }
    for(int i = 0; i < n; i++){         // ���� �̸� �Է�
        scanf("%s", city[i]);\
        getchar();
    }
    
    
    for(int i = 0; i < n; i++){             //  n�� �ݺ�
        scanf("%d", &count[i]);             // ������ ���� �Է�
        getchar();          
        list[i] = (tourcity *) malloc( sizeof(tourcity) * count[i]);        // ������ ������� �����Ҵ� �� Ȯ��
        if(list[i] == NULL){
            printf("Not Enough Memory.\n");
            return 0;
        }
    }

    for(int i = 0; i < n; i++){             // ���� ������ŭ �ݺ�
        for(int j = 0; j < count[i]; j++) {     // ������ ���� ��ŭ �ݺ�
            scanf("%s %d %c %s",list[i][j].name, &list[i][j].fee, &list[i][j].in_out, list[i][j].start_day);        // ����ü�� �Է�
            strcpy(list[i][j].city_name, city[i]);  // ���� �̸� ����
        }
    }

    result = list[0][0];        // ��� �� ���� 0��° ������ �ʱ�ȭ

    for(int i = 0; i < n; i++){         // ���� ������ŭ �ݺ�
        for(int j = 0; j < count[i]; j++) {     // ������ ���� ��ŭ �ݺ�
            if(list[i][j].fee > result.fee){        // ��� ��
                result = list[i][j];            // ����� ���� 
            }
            else if(list[i][j].fee == result.fee){  // ����� ���� ���
                if(strcmp(list[i][j].start_day,result.start_day) < 0){
                    result = list[i][j];            // ���� ��¥ �� �� ����� ����
                }
            }
        }
    }


    printf("%s %s %d %s %c\n", result.city_name, result.name, result.fee, result.start_day, result.in_out);
                //��� ���



    for(int i = 0; i < n; i++){
        free(city[i]);          // ���� �̸� ���� ������ �޸� ��ȯ
        free(list[i]);          // ������ ���� ����ü ������ �޸� ��ȯ
    }
    free(list);             // ����ü �޸� ��ȯ
    free(city);             // ���� �޸� ��ȯ
    free(count);            // ������ ���� ���� ������ �޸� ��ȯ

    return 0;
}