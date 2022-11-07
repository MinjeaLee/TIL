#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

void swap(int **ppx, int **ppy);

int main()
{
    int *px = NULL, *py = NULL;
    int x, y;

    px = &x;
    py = &y;

    scanf("%d %d", px, py);

    swap(&px, &py);
    printf("%d %d", *px, *py);
}

void swap(int **ppx, int **ppy)
{
    int *tmp = NULL;

    tmp = *ppx;
    *ppx = *ppy;
    *ppy = tmp;
}