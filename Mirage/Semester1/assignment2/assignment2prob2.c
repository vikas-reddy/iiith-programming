#include<stdio.h>
main()
{
	int n,m,l,k=0;
	scanf("%d",&n);
	for(m=1;m<=n;m++)
	{	if((n%m)==0)    
		{   for(l=1;l<=m;l++)
			{     
			      if ((m%l)==0)
			        k++;
			}
			           if(k==2)
			      {
				printf("%d ",m);
			      }
		              k=0;
		}
	}
}	
