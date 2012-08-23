#include<stdio.h>
int myisalnum(int c)
{
	if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'))   return 1;
	else return 0;
}
int myisalpha(int c)
{
       if((c>='a' && c<='z')||(c>='A' && c<='Z'))  return 1;
       else return 0;
}
 int myisdigit(int c)
{
	if(c>='0' && c<='9')  return 1;
	else return 0;
}
int myisgraph(int c)
{
	if(c!=' '&& c!='\t' && c!='\n')  return 1;
	else  return 0;
}
 int myislower(int c)
{
	if(c>='a' && c<='z') return 1;
	else return 0;
}
int myisupper(int c)
{
	if(c>='A' && c<='Z') return 1;
	else return 0;
}
 int myisprint(int c)
{
	if(c>=32 && c<=126) return 1;
	else return 0;
}
int myispunct(int c)
{
	if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')) return 0;
	else return 1;
}
 int myisspace(int c)
{
	if(c==' ' || c=='\f' || c=='\r' || c=='\t' || c=='\v')  return 1;
	else return 0;
}


int mytoupper(int c)
{
	if(c>='a' && c<='z') return (c-32);
	else return c;
}
	
int mytolower(int c)
{
	if(c>='A' && c<='Z') return (c+32);
	else return c;
}
int myisxdigit(int c)
{
	if((c>='0' && c<='9')||(c>='a' && c<='f')||(c>='A' && c<='F')) return 1;
	else return 0;
}
int myatoi(char *c)
{
	int i=0,n=0;
	for(i=0 ; c[i]!='\0' ; i++)
	{
		if(c[i]>='0' && c[i]<='9')
			n=n*10 +c[i]-'0';
	}
	return n;
}
long myatol(char *c)
{
	int i=0;
	long n=0;
	for(i=0 ; c[i]!='\0' ; i++)
	{
		if(c[i]>='0' && c[i]<='9')
			n=n*10 +c[i]-'0';
	}
	return n;
}	
long long myatoll(char *c)
{
	int i=0;
	long long n=0;
	for(i=0 ; c[i]!='\0' ; i++)
	{
		if(c[i]>='0' && c[i]<='9')
			n=n*10 +c[i]-'0';
	}
	return n;
}      
long long myatoq(char *c)
{
	int i=0;
	long long n=0;
	for(i=0 ; c[i]!='\0' ; i++)
	{
		if(c[i]>='0' && c[i]<='9')
			n=n*10 +c[i]-'0';
	}
	return n;
}



