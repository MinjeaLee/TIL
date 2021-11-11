#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _st{         // ����ü ����
    char *str;              // ���ڿ� ����
    int cnt1, cnt2;         // ������ ����, ������ ����
    int num;                // ���� ����
    int result1, result2;   // ��� 1, 2 ����
}st;

int main(){
    st *list, *p_i, tmp;    // ����ü ����, ������, tmp ����
    int n, len, num, cnt_vowel, num_count;  // n, ���ڿ� ����, ����, ���� ����, ���� ���� ���� ����
    char vowel[10] = {'A', 'a', 'E', 'e', 'i', 'o', 'u', 'I', 'O', 'U'};    // ������ Ȯ���ϱ����� ��� ���� ����Ʈ�� ����
    char str_tmp[101];          // �Է¹��� ���ڿ����� ����

    scanf("%d", &n);        // n �Է�
    getchar();      

    list = (st *)malloc(sizeof(st) * n); // n�� ����ü �����Ҵ�
    if(list == NULL){               // �����Ҵ� �ȵǾ��ٸ� -1��ȯ�ϰ� ����
        return -1;
    }

    for(p_i = list; p_i < list + n; p_i++){     // n�� �ݺ�
        scanf("%s", str_tmp);               // ���ڿ� �Է�
        getchar();          
        len = strlen(str_tmp);              // ���ڿ� ���� ����
        p_i->str = (char *)malloc(sizeof(char) * len + 1); // ���ڿ� ���� + 1 ��ŭ �����Ҵ�
        if(p_i->str == NULL){               // �����Ҵ� �ȵǾ��ٸ� -1��ȯ�ϰ� ����
            return -1;
        }
        strcpy(p_i->str, str_tmp);          // ���ڿ��� ����ü�� ����
    }
    
    for(p_i = list; p_i < list + n; p_i++){     // n���ݺ�
        num = 0;                                // ī��Ʈ���� ������ �ʱ�ȭ
        num_count = 0;
        cnt_vowel = 0;
        for(int i = 0; i < strlen(p_i->str); i++) {     // ���ڿ��� ���̸�ŭ �ݺ�
            for(int j = 0; j < 10; j++){                // ����������ŭ �ݺ�
                if(p_i->str[i] == vowel[j]) {           // ������ �ִٸ�
                    cnt_vowel++;                        // �������� ++
                }
            }
            if('0' <= p_i->str[i] && p_i->str[i] <= '9') {      // ���ڶ�� 
                num *= 10;                                      // ���ڰ� ���� �ڸ����� �𸣱⿡ ���� ���� * 10
                num += p_i->str[i] - '0';                       // ���� ����
                num_count++;                                    // ���� ���� ++
            }
        }
        p_i->cnt1 = strlen(p_i->str) - cnt_vowel - num_count;         // ���� ������ ���ڿ� ���� - ���� ���� - ���ڰ���
        p_i->cnt2 = cnt_vowel;                                      // �������� ����
        p_i->num = num;                                             // ���� ����
        if(p_i->cnt1 > p_i->cnt2){                                  // ���ǿ� ���� return1, return2 ����
            p_i->result1 = p_i->cnt1 * num;
            p_i->result2 = p_i->cnt2 * num;
        }
        else{
            p_i->result1 = p_i->cnt2 * num;
            p_i->result2 = p_i->cnt1 * num;
        }
    }

    for(int i = 0; i < n - 1; i++){                         // ����
        for(p_i = list; p_i < list + n - i - 1; p_i++) {    
            if(p_i->result1 < (p_i + 1)->result1){  // �ڿ� �ε����� result1�� �� ũ�� ����
                tmp = *p_i;
                *p_i = *(p_i + 1);
                *(p_i + 1) = tmp;
            }
            else if(p_i->result1 == (p_i + 1)->result1){    // result1�� ���� 
                if(p_i->result2 < (p_i + 1)->result2){      // �ڿ� �ε����� result2�� �� ũ�� ����
                    tmp = *p_i;
                    *p_i = *(p_i + 1);
                    *(p_i + 1) = tmp;
                }
            }
        }
    }

    for(p_i = list; p_i < list + n; p_i++){         // ��� ������� ���
        printf("%s\n", p_i->str);
    }   
    for(p_i = list; p_i < list + n; p_i++){         // ���ڿ� �޸� ��ȯ
        if(p_i->str != NULL){                       // null �� �ƴѰ�츸
            free(p_i->str);                         // ���ڿ� �޸� ��ȯ
            p_i->str = NULL;                        // �޸� ����
        }
    }
    if(list != NULL){                                // ����ü �޸� ��ȯ null�� �ƴѰ�츸
        free(list);                                  // ��ȯ
        list = NULL;                                 // �޸� ����
    }

    return 0;
}