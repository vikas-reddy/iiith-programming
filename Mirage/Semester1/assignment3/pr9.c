#include<stdio.h>
main()
{
	int i,j,m,n,k,l ;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{	
	    if(i>=0&&i<=n-2)
	    {	
	       for(j=1;j<=i;j++)
	       {
		     printf(" ");
	       }
	       printf("**");
	       for(k=1;k<=2*(n-i-2);k++)
	       {
		       printf(" ");
	       }
	       printf("*\n");
	   }	       
	
	   if(i==(n-1))
	   {
		for(m=1;m<=i;m++)
		{
			printf(" ");
		}
		printf("*\n");
	   }

	}
}








