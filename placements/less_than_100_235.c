#include<stdio.h>

int main()
{
	int i=1, count=0;
	for(i=1; i<=100; i++)
	{
		if( (i%2 != 0) && (i%3 != 0) && (i%5 != 0) )
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
