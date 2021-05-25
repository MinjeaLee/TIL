#include <stdio.h>

int main()
{
    int n, x[20], y[20], i, tmp, j, p_c;
    double avg, grade[20], score[20];
    scanf("%d", &n);
    p_c = n * 0.7;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        avg = (x[i] * 0.4 + y[i] * 0.6);
        grade[i] = avg;
        score[i] = grade[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (grade[i] < grade[j])
            {
                tmp = grade[i];
                grade[i] = grade[j];
                grade[j] = tmp;
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (grade[i] == grade[j])
            {
                grade[j] = -1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        printf("%d ", x[i]);
        printf("%d ", y[i]);
        printf("%0.1lf ", score[i]);
        for (j = 0; j < n; j++)
        {
            if (score[i] == grade[j])
            {
                printf("%d ", j + 1);
                if (j + 1 <= p_c || y[i] >= 80)
                {
                    printf("P\n");
                }
                else
                {
                    printf("F\n");
                }
            }
        }
    }

    return 0;
}