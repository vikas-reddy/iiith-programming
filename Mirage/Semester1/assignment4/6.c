#include<stdio.h>
main()
{
	int n,C=0,l,j,i=0,f,a[30];
	scanf("%d",&n);
	a[0]=n;
	while(n!=0)
	{
		l=n%10; 
		n=(n-l)/10; 
		C=C+l*l*l;
		if(n==0)
		{
			i++;
			a[i]=C;
			for(j=0;j<i;j++)
			{
				if(a[i]==a[j])
				{	
					printf("%d\n",i-j);f=1; break;
				}
			}
		n=C;
		C=0;
		}
		if(f==1) break;
	}
}
