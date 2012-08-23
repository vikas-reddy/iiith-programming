#include<stdio.h>

int print_function(int value)
{
	printf("Function Entered %d\n", value);
}

int main()
{
	int (*p)[10];
	/*
	int (*pf)();
	pf = print_function;
	*/

	int (*pf)(int) = print_function;

	pf(29);
	return 0;
}
