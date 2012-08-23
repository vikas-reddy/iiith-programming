#include<stdio.h>
main()
{
	int N,i,j,k;
	/* vikas reddy sripathi */
	scanf("%d",&N);	
	printf("/* /*  */");	
		for(i=1;i<=2*N+1;i++)
		{
			if(i==N+1)
			{
				for(j=1;j<=2*N+1;j++)
				{	
					printf("* ");
				}
				printf("\n");
			}
			else
			{
				/*  Mahesh Raja  */
				
				for(k=1;k<=2*N;k++)
					printf(" ");
				printf("*\n");
			}

		}
}

