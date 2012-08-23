#include<stdio.h>

main(){
	int a,b,c,i=0,n;
	scanf("%d%d%d",&a,&b,&n);
	do{c=a+b;
		printf("%d\n",c);
		a=b;
		b=c;
		i++;}
	while(i<=(n-1));
}

