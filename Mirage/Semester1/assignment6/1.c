#include<stdio.h>
int GCD(int a,int b)
{
	if(a%b==0) return b;
	return (GCD(b,a%b));
}
main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",GCD(a,b));
}
			
		
