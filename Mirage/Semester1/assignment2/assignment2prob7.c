#include<stdio.h>
main()
{
	int n,m,r,i,A,B;
	scanf("%d %d",&n,&r);
	if(n<r)
		printf("C(n,r) does'nt exist\n");
	else{ 
		if(n==0)	A=1;
		   else {A=1;m=n;
			  for(i=0;i<r;i++)
			  { A=A*m ; m-- ; }
		        }
		if(r==0)   B=1;
		else
			for(B=1;r!=0;B=B*r,r--);
	}
	printf("%d\n",(A/B));
}
