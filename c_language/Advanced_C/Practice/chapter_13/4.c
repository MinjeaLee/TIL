#include <stdio.h>
#include <string.h>

int main() {
	unsigned int n;
	int x, y, z, k;

	scanf("%d %d %d %d", &x, &y, &z, &k);

	n = (unsigned int)x;
	n = n << 8;
	n = n | (unsigned int)y;
	n = n << 8;
	n = n|(unsigned int)z;
	n = n << 8;
	n = n|(unsigned int)k;

	printf("%d", n);
    
    return 0;
}