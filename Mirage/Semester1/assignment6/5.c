#include<stdio.h>
main()
{
	int i=0,j=0;
	char a[100],*b;
	scanf("%[^\n]",a);
	b=a;
	for(i=0; a[i]!='\0'; i++)
	{
		if(a[i]>='A' && a[i]<='Z')  a[i]=a[i]+32;
		if(a[i]>='a' && a[i]<='z')
		{
			a[j]=a[i]; j++;
		}
	}
	a[j]='\0';
	while(*b!='\0') b++;b--;
	printf("%d\n",pali(a,b));
}
int pali(char *str,char *t)
{
	if(str-t>=0) return(1);
	if(*str==*t) return(pali(str+1,t-1));
	else return(0);
}
			
