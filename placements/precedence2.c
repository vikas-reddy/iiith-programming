#include<stdio.h>

main()
{
	int i=3;
	while(i--)
	{
		printf("i = %d\n",i);
		int i=100;
		i--;
		printf("%d..\n",i);
	}

}
