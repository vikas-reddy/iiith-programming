#include<stdio.h>
main()
{
	int i,j,t,c,c1=0;
	char a[100],b[100],d[100];
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++,c1++);
	/*for(i=0;b[i]!='\0';j++,c2++);
	i=c1;j=c2;
	while(a[i]!='\0' && b[j]!='\0')
	{
		S=a[i]+b[j]+carry;
		carry=S/10;*/
	for(i=0;i<c1/2;i++)
	{
		t=a[i];
		a[i]=a[c1-i];
		a[c1-i]=t;
	}
	for(i=0;i<=c1;i++) printf("%d",a[i]-'0');
}
