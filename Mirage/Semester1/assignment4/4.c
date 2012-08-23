#include<stdio.h>
main()
{
	int i=0,j=0;
	char c,file[100],a[1000];
	FILE *f;
	scanf("%s",file);
	f=fopen(file,"r");
	while(fscanf(f,"%c",&c)!=EOF)
	{
		a[i]=c;i++;
	}
	while(j<i)
	{
		if(a[j]=='i'&&a[j+1]=='n' && a[j+2]=='d' && a[j+3]=='i'
				&& a[j+4]=='a')
		{
			printf("bharat");j=j+5;
		}
		else
		{
			printf("%c",a[j]);  j=j+1;
		}
	}
}		

