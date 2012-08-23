#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p=NULL;
	int i=0;

	p = (int *)calloc(1, sizeof(int));

	//p = (int *)realloc(p, 22*sizeof(int));


	for(i=0; i<100; i++)
		p[i] = 100*i;

	for(i=0; i<100; i++)
		printf("%d ", p[i]);
	printf("\n");

	free(p);
	if(!p)
		printf("p is free after free()\n");
	return 0;
}
