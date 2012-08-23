#include<stdio.h>

int main()
{
	int x=-1;

  printf("!x = %d\n", !!x);
	if(!!x)
		printf("%d", !!x);
	else
		printf("%d", !x);
	printf("\n");
	return 0;
}
