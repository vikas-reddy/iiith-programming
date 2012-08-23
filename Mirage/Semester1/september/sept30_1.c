#include<stdio.h>
int palindr(char *str)
{
	char *s1,*s2;
	int i=0,j=0;
	s1=str;  s2=str;
	while(*s2!='\0')
	{  
		i++;
		s2=s2+1;
	}
	s2=s2-1;
	while(1)
	{
		if(*s1==*s2)
		{
			if(j==(i/2)+1) return 1;
			s1=s1+1;  s2=s2-1;
			j++;
		}
		else return 0;
	}
}
main()
{
	char string[100];
	scanf("%s",string);
	printf("%d\n",palindr(string));
}
				
