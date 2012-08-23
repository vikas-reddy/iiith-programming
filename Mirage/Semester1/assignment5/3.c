#include<stdio.h>
#include<math.h>
main()
{
	int n;
	scanf("%d",&n);
	double a[n][n],t;
	int i,j,k,c=0,l,Q=1;
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++) 
			scanf("%lf",&a[i][j]);
	for(k=0;k<n-1;k++)
	{	
		if(a[k][k]==0)
		{
			for(c=k+1;c<n;c++)
			{ 
				if(a[c][k]!=0)
				{
					for(l=0;l<n+1;l++)
					{       t=a[l][k];
						a[l][k]=-a[c][k];
						a[c][k]=t;
					}	break;
				}
			}
		}		
		for(j=k+1;j<n;j++)
		{	
			t=a[j][k]/a[k][k];
			for(i=k;i<n;i++)
				a[j][i]=a[j][i]-t*a[k][i];
		}
	}	
	for(i=0;i<n;i++)
	{
		Q=Q*a[i][i];
	}
	if(Q==0) printf("YES\n");
	else printf("NO\n");
}
