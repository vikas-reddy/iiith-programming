#include<stdio.h>

int main()
{
	const char *p = "vikas";

	//p[2] = 'X';
	p[0] = 'X';

	printf("%s\n", p);
}
