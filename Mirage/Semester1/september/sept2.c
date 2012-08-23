#include<stdio.h>
main()
{
	char s1[10],s2[10],s3[20];
	int  i,j,t,a,k;
	scanf("%s",s1);
	for(i=0,a=0 ; s1[i]!='\0'; i++,a++);
	for(i=0 ; i<a ; i++)
	{
		s2[i] = s1[a-1-i];
	}
	for(i=0 ; i<a ; i++)
	{
		s3[j]=s1[i];
		j++;
	}
	k=j;
	for(i=0 ; i<a ; i++,k++)
	{
		s3[k]=s2[i];

	}
	for(i=0;i<a;i++)
	{
		printf("%c ",s2[i]);
	}
	printf("\n");
	for(i=0;i<2*a;i++)
	{
		printf("%c ",s3[i]);
	}
	printf("\n");
}
		
