#include<stdio.h>
#include<stdlib.h>

void fnc(void)
{
	static int x = 8;
	return;
}

int main()
{
	fnc();
	static int x;
	//int x = 10;
	printf("%d\n", x);
	return 0;
}
