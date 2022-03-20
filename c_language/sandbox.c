#include <stdio.h>

int is_prime(int n) {
    int n1, i;
    n1 = n;
    for (i = 2; i < n; i++) {
        while (n % i == 0)
            n = n / i;
    }
    if (n == n1) {
        return 1;
    }
    else
        return 0;

}
int main() {
    int num, i, num1, count = 0;
    scanf_s("%d", &num);

    if (!is_prime(num))
    {
        printf("%d=", num);
        num1 = num;
        for (i = 2; i <= num; i++) {
            count = 0;
            while (num % i == 0) {
                count += 1;
                num = num / i;
            }
            if (num1 % i == 0) {
                if (num != 1) {
                    printf("%d^%d*", i, count);
                }
                else if(num==1){
                    printf("%d^%d", i, count);
                    break;
                }
            }
        }
    }

}