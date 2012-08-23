#include<stdio.h>
#include<stdlib.h>
#define circum(r) 3.14*r*r

struct a{

	char c;

	union{
		int i;
		short s;
		char arr[10];
	}b;

	struct a *ptr;

	struct c{
		struct a *p;
		int i[15];
		short c[100];
	}d;

	int *iptr;
	char *cptr;
}e;

main()
{
	int i=10;
	char ch='5';
	const *p1 = &i;
	int const *p2 = p1;
	int * const p3 = &i;
	//printf("%d %d\n", *p2, ++*p3);
	//return;


	   int x=5;
	   printf("%d %d %d %d %d\n", --x, x--, x, ++x, x++);
	   //printf("%d %d %d %d %d\n", printf("x\n"), printf("xx\n"), printf("xxx\n"), printf("xxxx\n"), printf("xxxxx\n"));
}
