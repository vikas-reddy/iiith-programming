#include<stdio.h>
main()
{
	int i,j,n,t;
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{   for(j=0;j<n;j++)
	    {
		 scanf("%d",&a[i][j]);
	    }
	}
	for(i=0;i<n;i++)
	{   for(j=0;j<n;j++)
	    {
		 t=a[i][j];
		 a[i][j]=a[j][i];
		 a[j][i]=t;
	    }
	}
	printf("-------------\n");
	for(i=0;i<n;i++)
	{   for(j=0;j<n;j++)
	    {
		    printf("%d ",a[j][i]);
	    }
	    printf("\n");
	}

}
