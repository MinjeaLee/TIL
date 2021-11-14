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
    stu *list, *p, tmp;     // ����ü ����, ������, ���� ���� tmp ����
    int n, k, blank_count;     // n, k, ���� ���� ���� ����
    int max_score_index;        // psub������ ���� ū ������ ��ġ ã�� ����
    char str[101], *p_str;      // �Է� ���ڿ�, ���ڿ� ������ ����
    int start_index = 0, end_index = 0; // ���� ���ڿ��� ��� ��ġ�� �ִ��� ã�� ���� ����, 
    double sub_score, total, max_score = -1;    // ��������, ���� ����, �ִ� ���� ���� ����
    
 
    scanf("%d", &n);            // n �Է�
    getchar();                  // getchar

    list = (stu *)malloc(sizeof(stu) * n);  // ����ü �Ҵ�
    for(int i = 0; i < n; i++){     // n�� �ݺ� ���� ����
        gets(str);                  // ���ڿ� �Է�
        start_index = 0;            // ����, �� �ε��� �ʱ�ȭ
        end_index = 0;  
        for(;str[end_index] != '\0';end_index++){ // �� �ε��� ++ �ϸ鼭 ���� ã��
            if(str[end_index] == ' '){  // �����̶��
                list[i].name = (char *)calloc((end_index - start_index + 1) ,sizeof(char)); // ���� ���� ũ�� ��ŭ �Ҵ�
                strncpy(list[i].name, str + start_index, end_index - start_index); // ���� ���� ���� ���� ���� ũ�⸸ŭ ����
                end_index ++;   // ���� �� �ε��� ���� �̹Ƿ� ++
                start_index = end_index;    // ���� �ε��� �ʱ�ȭ
                break;
            }
        }
        for(;str[end_index] != '\0'; end_index++){      // �� �ε��� ++ �ϸ鼭 ���� ã��
            if(str[end_index] == ' '){                  // �����̶�� id ����
                strncpy(list[i].id, str + start_index, 4);  //  id ����
                list[i].id[4] = '\0';           // ���� �ι��� ����
                end_index++;                // ���� �� �ε��� ���� �̹Ƿ� ++
                start_index = end_index;    // ���� �ε��� �ʱ�ȭ
                break;
            }
        }
        blank_count = 0;        // ���� ���� �ʱ�ȭ ���� ������ ���� ���� /2 + 1 -> ���� ����
        for(;str[end_index] != '\0'; end_index++){  // �� �ε��� ++ �ϸ鼭 ���� ã��
            if(str[end_index] == ' '){  // �����̶��
                blank_count++;      // ���� ���� ++
            }
        }
        list[i].numSubject = blank_count / 2 + 1;       // ���� �� ����

        list[i].psub = (sub *)malloc ( sizeof(sub) * list[i].numSubject);       // ����� ��ŭ �����Ҵ�

        total = 0;                      // ���� �ʱ�ȭ
        for(int j = 0; j < list[i].numSubject; j++){        // �������ŭ �ݺ�
            for(end_index = start_index + 1; str[end_index] != '\0'; end_index++){ // �� �ε��� ++ �ϸ鼭 ���� ã��
                if(str[end_index] == ' '){  // �����̶��
                    list[i].psub[j].name = (char *)malloc(sizeof(char) * (end_index - start_index) + 1); // // ���� ���� ũ�� ��ŭ �Ҵ�
                    strncpy(list[i].psub[j].name, str + start_index, end_index - start_index);  // ���� ���� ���� ���� ���� ũ�⸸ŭ ����
                    end_index ++;   //  ���� �� �ε��� ���� �̹Ƿ� ++
                    start_index = end_index;    // ���� �ε��� �ʱ�ȭ
                    break;
                }
            }
            sub_score = 0;  // �� ������ ���� �ʱ�ȭ
            if('0' <= str[end_index] && str[end_index] <= '9'){ // ���ڰ� 100�� �� �� �����Ƿ� ���� üũ
                sub_score *= 10;        // ���� * 10
                sub_score += str[end_index] - '0'; // ���ڸ��� ���� INT������ ����
                if('0' <= str[end_index + 1] && str[end_index+ 1] <= '9'){  // 2��° ���� üũ
                    sub_score *= 10;        // ���� * 10
                    sub_score += str[end_index + 1] - '0';  // ���ڸ��� ���� INT������ ����
                    if('0' <= str[end_index + 2] && str[end_index + 2] <= '9'){     // 3��° ���� üũ
                        sub_score *= 10;        // ���� * 10
                        sub_score += str[end_index + 2] - '0';  // ���ڸ��� ���� INT������ ����
                        start_index++;      // ���� �ε��� ++
                    }
                    start_index++;          // ���� �ε��� +=
                }
                start_index++;              // ���� �ε��� ++
            }
            list[i].psub[j].score = sub_score;  // ���� ����
            total += sub_score;         // ���� ���
        }
        list[i].avg = total / list[i].numSubject;       // ��� ���
    }

    scanf("%d", &k);            // K�Է�

    for(int i = 0; i < n - 1; i++){     // ���� ���� ���
        for(p = list ; p < list + n - 1; p++){ 
            if(p->avg < (p + 1)->avg){          // ���� ����� ũ�ٸ�
                tmp = *p;                   // ����
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
            else if (p->avg == (p+1)->avg){     // ����� ���ٸ�
                if(strcmp(p->id, (p + 1)->id) > 0){     // ID��
                    tmp = *p;               // ����
                    *p = *(p + 1);
                    *(p + 1) = tmp;
                }
            }
        }
    }
    
    for(int i = 0; i < list[k - 1].numSubject; i++){        // K ��° �л��� ���� ū ���� �˻�
        if(list[k - 1].psub[i].score > max_score){          // MAX ���� ũ�ٸ�
            max_score_index = i;                            // �ε��� ����, MAX �ʱ�ȭ
            max_score = list[k - 1].psub[i].score;
        }
    }

    printf("%s %s %.2lf %s %.2lf\n", list[k - 1].name, list[k - 1].id, list[k - 1].avg, list[k - 1].psub[max_score_index].name, list[k - 1].psub[max_score_index].score);

        // ��� ���

    for(int i = 0; i < n; i++){                         // �޸� ��ȯ
        for(int j = 0; j < list[i].numSubject; j++){
            free(list[i].psub[j].name);
        }
        free(list[i].name);
    }
    free(list);

    return 0;
}