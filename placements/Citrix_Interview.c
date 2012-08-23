#include<stdio.h>


void foobar(int **p)
{
	int a=20;
	int *b=&a;
	int **c=&b;

	*p = *c;
	return;
}

int main()
{
	int a=10;
	int *b=&a;
	int **c=&b;


	printf("%d %d %d\n", a, *b, **c);

	foobar(c);

	printf("%d %d %d\n", a, *b, **c);

	return 0;
}

