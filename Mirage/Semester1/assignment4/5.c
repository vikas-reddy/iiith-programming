#include<stdio.h>
#include<math.h>
main()
{
	int i,n,l,o,q,r,c,k=0;
	long long int p=0,m=0;
	scanf("%d",&n);
	for(m=n;m<1000000;)
	{
		k=m*n;
		p=m;
		for(o=m;o!=0;)
		{
			l=o%10;  o=(o-l)/10; c++;
		}
		q=p%10;
		p=(p-q)/10;
	        p=q*pow(10,c-1)+p;
		c=0;
		if(p==k) {printf("%ld\n",m);break;}
		if(m>1)
		{m=m+10;p=0;}
	}
}
