#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char a[10];

	strcat(a,'0' + 1);

	printf("%s\n", a);
	

	return 0;
}