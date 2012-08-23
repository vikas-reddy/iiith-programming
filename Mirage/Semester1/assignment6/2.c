#include<stdio.h>
#include<string.h>
void reverse(char *str)
{
	int i=0;
	for(  ;i<(strlen(str))/2; i++)
	{
		str[i]=str[strlen(str)-i-1]+str[i];
		str[strlen(str)-i-1]=str[i]-str[strlen(str)-i-1];
		str[i]=str[i]-str[strlen(str)-i-1];
	}
}
main()
{
	char a[100];
	scanf("%s",a);
	reverse(a);
	printf("%s\n",a);
}
		



