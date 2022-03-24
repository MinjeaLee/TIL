#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int a[10];
	int min, max, sum=0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		min = max = a[0];
		if (min >= a[i]) min = a[i];
		if (max <= a[i]) max = a[i];
		sum =sum+ a[i];
	}
	printf("Min : %d\nMax : %d\nAverage : %d", min, max, sum / 10);
	return 0;
}