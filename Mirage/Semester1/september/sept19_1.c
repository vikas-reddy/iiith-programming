#include<stdio.h>
int myfact(int n)
{
	int ans;
//	printf("%d ",n);
	if(n==1) return 1;
//	printf("%d ",n);
	ans=n*myfact(n-1);
	printf("%d ",n);
	return ans;
}
main()
{
	int n,a;
	scanf("%d",&n);
	a=myfact(n);
	printf("\n%d\n",a);
}
