#include<stdio.h>
main()
{
	int s,b,t,ways=0,i;
	float sum;
	for(s=5;s>=1;s--)
	{
		for(b=5;b>=0;b--)
		{
			for(t=5;t>=0;t--)
			{
				sum=(4*s)+(1.5*b)+(0.5*t);
				i=sum;
				if(i==sum && i%20==0)
				{
					ways++;
				}
			}
		}
	}
	printf("%d\n",ways);
}
