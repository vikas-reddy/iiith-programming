#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#define  MAX_COUNT 200
#define  BUF_SIZE 100

main(void)
{
	pid_t pid;
	int j=7, *i=&j;

	if(0 == fork())
		*i = *i + 10;
	else
	{
		*i = *i + 20;
	}

	printf("%d\n", j);
	//fork();
	pid=getpid();
	printf("\n%d\n", pid);
}
