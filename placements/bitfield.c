#include<stdio.h>
#include<stdlib.h>

int main()
{
	struct something
	{
		int x:30;
		//int:1;
		char ch:3;
	};

	struct something s1;

	printf("%d\n", sizeof(struct something));
	return 0;
}
