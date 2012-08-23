#include<stdio.h>
main()
{
	long int n;
	int m,s=0;
	scanf("%d",&n);
	while(n!=0)
	{
		m=n%10;
		n=(n-m)/10;
		s=s+m;
		if(s>9&&n==0) 
		{
			n=s;
			s=0;
		}
	}
	if(s==9) 
		printf("YES\n");
	if(s<9) 
		printf("NO\n");
}
