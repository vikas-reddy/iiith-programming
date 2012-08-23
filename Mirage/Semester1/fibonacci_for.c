#include<stdio.h>


main(){
	int a,b,c,i=0,n;
	scanf("%d%d%d",&a,&b,&n);
	for(i=0;i<=(n-1);i=i+1)
	{c=a+b;
		printf("%6d\n",c);
		a=b;
		b=c;
	} 
}
