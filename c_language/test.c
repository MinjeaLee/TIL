#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char buf[20];
	int i;

	gets(buf);

	i = atoi(buf);

	printf("%d\n", i);
	puts(buf);

	system("/bin/sh");
	// system(buf);


	return 0;
}