#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[101], str2[101], ** arr1 = NULL, ** arr2 = NULL, * p, * q;
    gets(str1), gets(str2);

    int cnt1 = 0;
    for (p = str1; *p; p++) {
        if (*p == ' ' || p == str1) cnt1++;
    }

    arr1 = (char**)malloc(cnt1 * sizeof(char*));
    if (arr1 == NULL) return -1;

    int cnt2 = 0;
    for (p = str2; *p; p++) {
        if (*p == ' ' || p == str2) cnt2++;
    }

    arr2 = (char**)malloc(cnt2 * sizeof(char*));
    if (arr2 == NULL) return -1;


    int index1 = 0;
    for (p = str1; *p; p++) {
        if (p == str1) {
            int n = 0;
            for (q = p; ; q++, n++) {
                if (*q == ' ') {
                    n++;
                    break;
                }
            }

            arr1[index1] = p;
            index1++;
        }

        if (*p == ' ') {
            int n = 0;
            for (q = p + 1; ; q++, n++) {
                if (*q == ' ' || q == str1 + strlen(str1)) {
                    n++;
                    break;
                }
            }

            *p = NULL;
            arr1[index1] = p + 1;
            index1++;
        }

    }

    int index2 = 0;
    for (p = str2; *p; p++) {
        if (p == str2) {
            int n = 0;
            for (q = p; ; q++, n++) {
                if (*q == ' ') {
                    n++;
                    break;
                }
            }

            arr2[index2] = p;
            index2++;
        }

        if (*p == ' ') {
            int n = 0;
            for (q = p + 1; ; q++, n++) {
                if (*q == ' ' || q == str2 + strlen(str2)) {
                    n++;
                    break;
                }
            }

            *p = NULL;
            arr2[index2] = p + 1;
            index2++;
        }
    }

    char* tmp;
    for (int i = 0; i < index2 - 1; i++) {
        for (int j = 0; j < index2 - 1; j++) {
            if (strlen(arr2[j]) < strlen(arr2[j + 1])) {
                tmp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = tmp;
            }

            if (strlen(arr2[j]) == strlen(arr2[j + 1])) {
                if (strcmp(arr2[j], arr2[j + 1]) > 0) {
                    tmp = arr2[j];
                    arr2[j] = arr2[j + 1];
                    arr2[j + 1] = tmp;
                }
            }
        }
    }

    int flag;
    char temp[101];
    for (int i = 0; i < index2; i++) {
        flag = 0;
        for (int j = 0; j < index1; j++) {
            for (int k = 0; k < index1; k++) {
                if (j == k) continue;
                strcpy(temp, arr1[j]);
                strcat(temp, arr1[k]);
                if (strcmp(temp, arr2[i]) == 0) {
                    printf("%s\n", arr2[i]);
                    flag = 1;
                    break;
                }
                if (flag == 1) break;
            }
            if (flag == 1) break;
        }
    }

    if (arr1 != NULL) {
        free(arr1);
        arr1 = NULL;
    }

    if (arr2 != NULL) {
        free(arr2);
        arr2 = NULL;
    }

    return 0;
}