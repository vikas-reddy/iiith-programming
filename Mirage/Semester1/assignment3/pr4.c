#include<stdio.h>
#include<math.h>
main()
{
	int k;
	float m,n,l,r,S;
	scanf("%f",&n);
	l=0;
	r=n;
	while(fabs(l-r)>.0001)
	{
		m=(l+r)/2.0;
		if(m*m-n>0)
			r=m;
		else
			l=m;
	}
	k=m*100;
	S=k/100.0;
	printf("%.2f",S);
}
	

