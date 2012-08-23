#include<stdio.h>

int fib(int n, int *p)
{
	return fib2(n, p);
}

int fib2(int n, int *p)
{
	if (n == 0 || n == 1)
	{
		*p = 0;
		return n;
	}
	else 
	{
		int pp;
		*p = fib2(n - 1, &pp);
		return pp + *p;
	}
}

int fib_iterative(int n)
{
	if(n==1 || n==2)
		return 1;
	int a=1, b=1, temp=0, i=0;
	for(i=1; i<n-2; i++)
	{
		temp = a;
		a = b;
		b = temp + b;
	}
	return b;
}

void fibonacci_series(int n)
{
	if(n <= 0)
		return;

	int i=0, temp, a=1, b=1;

	printf("%d ", a);

	for(i=0; i<n-1; i++)
	{
		printf("%d ", b);

		temp = a;
		a = b;
		b += temp;
	}

	printf("\n");
	return;
}

int main()
{
	int i=1, p=0, n=0;
	//for(  ;i<10; printf("%d\n", fib_iterative(i)), i++);

	while(scanf("%d", &n) != EOF)
	{
		fibonacci_series(n);
	}
	return 0;
}
