#include<stdio.h>
#include<math.h>
main()
{
	int x,i,j;
	float A,B,V,n,s;
	scanf("%d",&x);
	for(s=0,i=1,n=1;n>=0.000001;i++)
	{
		s=s+n;
		A=pow(x,i);
		for(V=1,j=1;j<=i;j++)
		{
			V=V*j;
		}
		B=V;
		n=A/B;
	}
	printf("ANSWER=%f\n",s);
}
