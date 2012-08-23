#include<stdio.h>
main()
{
	int n=0,c=0,m=0,i=0,ways=0;
	char ch;
	scanf("%c %d",&ch,&n);
	c=ch-96;
	m=c;
	for(i=1;i<=8;i++)
	{
		if((m+i)<9 && (n+i)<9)  ways++;

		if((m+i)<9 && (n-i)>0)  ways++;

		if((m-i)>0 && (n+i)<9)  ways++;

		if((m-i)>0 && (n-i)>0)  ways++;
	}
	printf(" %d\n",ways+14);
}

