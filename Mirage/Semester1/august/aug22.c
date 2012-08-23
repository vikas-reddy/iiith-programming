#include<stdio.h>
main()
{
	int p[26],i,max,m;
	char c;
	FILE *f;
	f=fopen("input1.txt","r");
	for(i=0;i<26;i++)
	{
		p[i]=0;
		while(fscanf(f,"%c",&c)!=EOF)
		{
			if(c>='a' && c<='z')
				p[c-'a'] ++;
			if(c>='A' && c<='Z')
				p[c-'A'] ++;
		
		max=0;
		m=0;
		for(i=0;i<=26;i++)
		{
			if(max<p[i])
			{
				max=p[i];
				m=i;
			}
		}
		printf("%c",m+'a');
	}
}
					
				
