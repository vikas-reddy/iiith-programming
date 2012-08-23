#include<stdio.h>
#include<string.h>


void somefunc()
{
	int a[5][4], i=0, j=0;
	printf("%d %d %d\n", (long)a, (long)(a[1]), (long)a[0][0]);
	return;
	for(i=0; i<5; i++)
	{
		for(j=0; j<4; j++)
			printf("%2d ", (long)&a[i][j] - (long)&a);
		printf("\n");
	}
}

void f(int n)
{
	if(n>0)
	{
		f(n--);
		printf("%d ",n);
		f(n--);
	}
}

main()
{
	char *p = "string";
	char q[]= "string";
	int i=0;

	printf("p = %d, q = %d\n", p=="string", q=="string");

	for(i=0; i<7; i++) printf("|%c|", p[i]);
	printf("\n");
	for(i=0; i<7; i++) printf("|%c|", q[i]);
	printf("\n");


	printf("%d, %d\n", p, q);
}
