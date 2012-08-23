#include<stdio.h>

main()
{
	char a[]="hello";
	char *b="hello";
	*(a+1) = 'E';
	printf("%c\n", b);
}
