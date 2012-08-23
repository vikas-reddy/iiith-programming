#include<stdio.h>
main()
{
	int i,j,a,b,k,n,m,l,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=3*n-2;i++)
	{
		if(i>=1 && i<=n)
		{
			for(i=1,a=2*n-3;i<=n && a<=6*n-7;i++,a=a+4)
			{
				for(j=1;j<=2*(n-i);j++)   printf(" ");
				if(i==1)
				{
					for(k=1;k<=n;k++)  printf("* ");
					printf("\n");
				}
				else
				{
					printf("*");
					for(l=1;l<=a;l++)  printf(" ");
					printf("*\n");
				}
			}
			
		}
		if(i>=n+1 && i<=2*n-1)
		{
			printf("*");
			for(m=1;m<=6*n-7;m++)  printf(" ");
			printf("*\n");
		}
	
                if(i>=2*n && i<=3*n-2)
		{
			for(i=2*n,z=6*n-11 ; i<=3*n-2 && z>=2*n-3 ; i++,z=z-4)
			{
				for(x=1;x<=2*(i-2*n+1);x++)   printf(" ");
				if(i==3*n-2)
				{
					for(y=1;y<=n;y++)  printf("* ");
					printf("\n");
				}
				else
				{
					printf("*");
					for(b=1;b<=z;b++)  printf(" ");
					printf("*\n");
				}
			}
		}
		
	}
}

