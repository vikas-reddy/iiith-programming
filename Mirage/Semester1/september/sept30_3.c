#include<stdio.h>
void rempunc(char *a)
{
	char *b,*temp;
	b=a; temp=b;
	while(*a!='\0')
	{
		if((*a>='a' && *a<='z')||(*a>='A'&&*a<='Z')||(*a>='0'&&*a<='9'))
		{	 *b=*a; a=a+1; b=b+1; 	}
		else a=a+1;
	}
	*b='\0';
	//return (b);
	printf("%s\n",temp);
}
main()
{
	char a[100];
	scanf("%s",a);
/*	printf("%s\n",*/rempunc(a);//);
}
		
	
