#include<stdio.h>
main()
{
	int N,n,m,p,ways=0;
	scanf("%d",&N);
	for(n=0;n<=N-1;n++)
	{
		for(m=0;m<=N-1;m++)
		{
			if((n*n-m*m+n-m)==2*N)
			{
				ways++;
				printf("%d = ",N);
				for(p=m+1;p<=n;p++)
	                        {
				    if(p>=m+1 && p<n)   	
					printf("%d+",p);
				    if(p==n)
					printf("%d",p);
				}
				printf("\n");
			}
		}
	}
	printf("%d\n",ways);
}






































































