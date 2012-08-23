#include<stdio.h>
main()
{
	int m,n,p,q,i,j,k,l;
	scanf("%d%d%d%d",&m,&n,&p,&q);
	if(n!=p) printf("multipliplication not defined\n");
	else
	{

		int a[m][n],b[p][q],c[m][q];
		for(i=0;i<m;i++)
		{  	for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<p;i++)
		{  	for(j=0;j<q;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		for(i=0;i<m;i++)
		{  	for(j=0;j<q;j++)
			{
				l=0;
				for(k=0;k<n;k++)
				{
					l=l+a[i][k]*b[k][j];
				}
				c[i][j]=l;
			}
		}
		for(i=0;i<m;i++)
		{  for(j=0;j<q;j++)
			{
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
	}
}


