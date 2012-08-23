#include<stdio.h>

int main()
{
	char *p = "%d%t%s";
	while(*p++ != 't');
	printf("%s\n", p);
	return 0;
}
