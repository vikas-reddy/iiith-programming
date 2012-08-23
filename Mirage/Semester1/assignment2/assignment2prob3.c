#include<stdio.h>
main()
{
	int m=0,n=0,i=0,ways=0;
	scanf("%d%d",&m,&n);
	for (i=1;i<=8;i++)
	{       
		if ((m-i)>0 && (n-i)>0)
		        ways++;
		if ((m+i)<9 && (n-i)>0)
			ways++;
		if ((m+i)<9 && (n+i)<9)
			ways++;
		if ((m-i)>0 && (n+i)<9)
			ways++;
	}
	printf("%d\n",ways);
}	
