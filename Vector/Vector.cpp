#include <iostream>
#include <stdio.h>
#include <stdlib.h>
unsigned Zer(unsigned n,int u) {
	unsigned b = 0;
	bool buf = 0;
	while (u > 0) {
		for (int i = 0; i < 4; i++) {
			buf = bool(n & (1 << u - i - 1));
			b = b | (buf << u * 2 - 1-i);
			b = b | (buf << u * 2 - 8 + i);
		}
		u = u - 4;
	}
	n = b;
	printf("%d\t", b);
	return n;
}
int main() {
	unsigned a = 0;
	char c[100];
	gets_s(c);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i]=='1') {
			a = a | (1 << strlen(c) - 1 - i);
		}
	}
	printf("%d\t", a);
	a=Zer(a,strlen(c));
	for (int i = 1; i <= strlen(c)*2; i++) {
		if (a & (1 << strlen(c)*2 - i)) {
			printf("1");
		}
		else printf("0");
	}
	return 0;
}