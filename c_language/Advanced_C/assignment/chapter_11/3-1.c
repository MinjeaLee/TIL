#include <stdio.h>
#include <string.h>

struct hotel_info
{

    char name[31], meal_check;
    int grade;
    double reputation, distance;
};

int in_hotel_info(struct hotel_info *p)
{
    int num = 0;

    for (;; p++)
    {
        scanf("%s", &p->name);
        if (strcmp(p->name, "0") == 0)
        {
            break;
        }
        scanf("%d %lf %lf %c", &p->grade, &p->reputation, &p->distance, &p->meal_check);
        getchar();

        num++;
    }
    return num;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info *p_struct, max, temp;
    double max_reputation = -1;
    int fast_check;

    for (p_struct = p; p_struct < p + N; p_struct++)
    {
        if (p_struct->grade >= G && p_struct->distance <= D)
        {
            if (p_struct->reputation > max_reputation)
            {
                max_reputation = p_struct->reputation;
                memcpy(&max, p_struct, sizeof(struct hotel_info));
            }
            if (p_struct->reputation == max_reputation)
            {
                fast_check = strcmp(p_struct->name, max.name);
                if (fast_check < 0)
                {
                    memcpy(&max, p_struct, sizeof(struct hotel_info));
                }
            }
        }
    }
    printf("%s %d %.1lf %.1lf %c", max.name, max.grade, max.reputation, max.distance, max.meal_check);
}
int main()
{
    struct hotel_info chart[100];
    int hotels_num, grade;
    double distance;

    hotels_num = in_hotel_info(chart);

    scanf("%d %lf", &grade, &distance);

    out_hotel_info(chart, hotels_num, grade, distance);

    return 0;
}