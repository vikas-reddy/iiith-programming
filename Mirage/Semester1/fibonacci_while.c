#include<stdio.h>

main(){
	int a,b,c,n,i=0;
	scanf("%d%d%d",&a,&b,&n);
	while(i<=(n-1))
	{
		c=a+b;
		printf("%d\n",c);
		a=b;
		b=c;
		i=i+1;
	}
}
