#include <stdio.h>
#include <string.h>

void ABC(int (*p)[20], int k1, int k2);

int main()
{
    int arr[20][20] = {0};
    int n, i, j;

    scanf("%d", &n);

    ABC(arr, n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }
}

void ABC(int (*p)[20], int k1, int k2)
{
    int i, j;

    for (i = 0; i < k1; i++)
        for (j = 0; j < k2; j++)
            (*(p + i))[j] = i + j;
}