#include<stdio.h>

#define TROB(n) (n^-n)&n


int main()
{
	unsigned x = 1;
	printf("%d\n", TROB(x));
	return 0;
}
