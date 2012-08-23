#include<stdio.h>

int main()
{
	int *i, *j;
	i = (int *)60;
	j = (int *)20;
	printf("%d\n", i-j);
	return 0;
}
