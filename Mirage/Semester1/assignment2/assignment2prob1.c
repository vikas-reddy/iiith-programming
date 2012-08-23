#include<stdio.h>
#include<math.h>
main()
{
	int n,i,F;
	float p=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{  p=p+log10(i) ;  }
 	F=p+1;
	printf("%d\n",F);
}
