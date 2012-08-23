#include<stdio.h>
main()
{
	int n,b,x,i,j;
	scanf("%d%d",&n,&b);
	printf("Su Mo Tu We Th Fr Sa\n");
	if(n>=2 && n<=7)
	{
		for(x=1;x<=8-n;x++)
		{
			printf("   ");
		}
	}
	i=8-n;
	for(j=1;j<=b;i++,j++)
	{
		printf("%2d ",j);
		if((i+1)%7==0) 
			printf("\n");
	}
}
			
