#include<stdio.h>
char reverse(char *a,int j)
{
	if(a[j]=='\0') {printf("%d\n",j);return;}
	j++;
	reverse(a,j);
//	printf("%c",a[j-1]);
}
main()
{
	int k=0;
	char a[20];
	scanf("%s",a);
	reverse(a,k);
}
