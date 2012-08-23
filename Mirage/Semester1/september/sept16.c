#include<stdio.h>
int mystrlen(char *str)
{
	int i,count=0;
	for(i=0;str[i]!='\0';i++,count++);
	return count;
}
int mystrcmp(char *str1,char *str2)	
{
	int n,i=0;
	while(1)
	{
		if(str1[i]==str2[i]) 
		{
			if( str1[i]=='\0' && str2[i]=='\0')
			{
				n=0;
				return n;
				break;
			}
			else i++;
		}
		else
		{
			n=str1[i]-str2[i];
			return n;
			break;
		}
	}
}
int mystrncmp(char *str1,char *str2,int N)	
{
	int n,a,i=0;
	while(1)
	{
		if(i<N-1 && str1[i]==str2[i]) 
		{
			if( str1[i]=='\0' && str2[i]=='\0')
			{
				n=0;
				return n;
				break;
			}
			else i++;
		}
		else 
		{
			n=str1[i]-str2[i];
			return n;
			break;
		}
	}
}
char *mystrcat(char *str1,char *str2)
{
	int i=0,j=0,c=0;
	for(i=0;str1[i]!='\0';i++,c++);
	i=c;
	while(str2[j]!='\0')
	{
		str1[i]=str2[j];
		i++;j++;
	}
	str1[i]='\0';
}
char *mystrncat(char *str1,char *str2,int N)
{
	int i=0,j=0,c=0;
	for(i=0;str1[i]!='\0';i++,c++);
	i=c;
		while(j<N)
		{
			str1[i]=str2[j];
			i++;j++;
		}
		str1[i]='\0';
}
/*
  main()
  {
  int n;
  char string1[20],string2[20];
  scanf("%s%s%d",string1,string2,&n);
  mystrncat(string1,string2,n);
  printf("%s\n",string1);
  }
*/

	
	
