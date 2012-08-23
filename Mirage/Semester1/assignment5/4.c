#include<stdio.h>
main()
{
	int n=5;
//	scanf("%d",&n);
	float a[n][n+1],t,u,w,x,y,z;
	int i,j,k,l,c;
	
	for(i=0;i<n;i++) 
		for(j=0;j<n+1;j++) 
			scanf("%f",&a[i][j]);
	for(k=0;k<n-1;k++)
	{	
		if(a[k][k]==0)
		{
			for(c=k+1;c<5;c++)
			{ 	
				if(a[c][k]!=0)
				{
					for(l=0;l<6;l++)
					{       t=a[l][k];
						a[l][k]=a[c][k];
						a[c][k]=t;
					}	
					break;
				}
			}
		}		
		for(j=k+1;j<n;j++)
		{	t=a[j][k]/a[k][k];
			for(i=k;i<n+1;i++)
				a[j][i]=a[j][i]-t*a[k][i];
		}
	}
	/*	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{	t=a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=t;
		}
		for(j=k+1;j<5;j++)
		for(i=0;i<6;i++)
		a[j][i]=a[j][i]-(a[j][k]/a[k][k])*a[k][i];
	 */ 
	z=a[4][5]/a[4][4];
	y=(a[3][5]-(a[3][4]*z))/a[3][3];
	x=(a[2][5]-a[2][3]*y-a[2][4]*z)/a[2][2];
	w=(a[1][5]-a[1][2]*x-a[1][3]*y-a[1][4]*z)/a[1][1];
	u=(a[0][5]-a[0][1]*w-a[0][2]*x-a[0][3]*y-a[0][4]*z)/a[0][0];	
	printf("%.2f %.2f %.2f %.2f %.2f\n",u,w,x,y,z);

}
