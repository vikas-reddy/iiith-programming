#include<stdio.h>
#include<string.h>

int main()
{
	char buffer[10] = "Genesis";
	printf("%d\n", &buffer[4] - buffer);
	return 0;
}
