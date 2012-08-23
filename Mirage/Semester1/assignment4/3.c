#include<stdio.h>
main()
{
	int n,k=0,i,j,m,u,v=0,l,x=0,y=0;
	scanf("%d",&n);
	for(i=2;i<=n/2;i++)
	{
		for(l=2;l<=i;l++)
		{
			if(i%l==0) k++;	
		}
		for(u=2;u<=n-i;u++)
		{
			if((n-i)%u==0) v++;
		}
		if(v==1 && k==1) 
		{	if(i!=(n-i))
			printf("%d %d \n",i,n-i);}
		k=0;
		v=0;
	}
}
