#include<stdio.h>
main()
{
	int n,i,k,l,h;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (k=1;k<=n-i;k++)
			printf(" ");
		for (l=i;l<=2*i-1;l++)
			printf("%d",l%10);
		for (h=2*i-2;h>=i;h--)
			printf("%d",h%10);
		printf("\n");
	}
}
