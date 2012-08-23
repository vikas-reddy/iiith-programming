#include<stdio.h>
main()
{
	int i,j,n,A,count=0,carry=0;
        char s[50],ch;
	scanf("%s%d",s,&n);
	for(i=0;s[i]!='\0';i++,count++);
	for(j=count;j>=0;j--)
	{
		A=n*(s[j]-'0');
		carry=A/10;
		A=A+carry;
	}
}
