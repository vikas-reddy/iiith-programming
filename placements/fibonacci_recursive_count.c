#include<stdio.h>

int count=0;

int fib(int n)
{
	count++;
	if(n <= 1)
		return 1;
	return (fib(n-1) + fib(n-2));
}

int main()
{
	int num=0;
	while(scanf("%d", &num) != EOF)
	{
		fib(num);
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}
