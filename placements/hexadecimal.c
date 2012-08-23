#include<stdio.h>

int main()
{
	int n=0x0086, i=0;
	for(i=0; i<100; i++)
	{
		n += 24;
		printf("%x\n", n);
	}
	return 0;
}
