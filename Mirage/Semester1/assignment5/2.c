#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int a[n][n],i,j,x=1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	i=0;j=n/2;
	while(x<=n*n)
	{
		if(i>=0 && j>=0)
		{ if(a[i][j]==0)  
			{        a[i][j]=x;x++;i--;j--;   }
		  else  {    	 j++;i=i+2;a[i][j]=x;x++;i--;j--;   }
 		}
		else 
		{	if(i<0 && j>=0) i=i+n; 
			if(i>=0 && j<0) j=j+n; 
		        if(i==j) {i=i+2;j=j+1;}
		}
	}	
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)   
		printf("%d ",a[i][j]);
	        printf("\n");
	}
	printf("\n");
}

	
