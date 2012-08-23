#include<stdio.h>
#include<math.h>
main()
{
	float x,m,n,s,A,B;
	int i,j,k;
	scanf("%f",&x);
	n=x;
	B=1;
	s=x;
	for(i=2;(n>=0.000001)||(n<=-0.000001);i++)
	{
		j=2*i-1;
                /*numerator part*/		
		A=(pow(x,j))*(pow(-1,i+1));
		/* denom. part*/
		for(k=1;k<=j;k++)
		{
			B=B*k;
		}
		n=A/B;
		s=s+n;
		B=1;
	}
	printf("cal=%f\nactual=%f\n",s,sinf(x));
}

			
				

