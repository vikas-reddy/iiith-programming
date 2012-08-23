#include <stdio.h>
main(int a,char *b[])
{
	int num=0,k,i,j,E,n,state=0;
	char ch;
	char c[1000];
	
	for(i=1 ; i<a ; i++)
	{
		if(b[i][0]=='-')
		{
			for(k=1;b[i][k]!='\0';k++)
			{
				if(b[i][k]=='E') E=1;
				else if(b[i][k]=='n') n=1;
			}
			
		}
		else state=1;
	}
	if(state!=1)
	{
		
			while(1)
			{
				scanf("%s",c);		
				num++;
				if(n==1) printf("    %d ",num);
				if(E!=1) printf("%s\n",c);
				else printf("%s$\n",c);
			}
	}

	num=0;
	for(i=1 ; i<a ; i++)
	{
		if(b[i][0]!='-')
		{
			FILE *f=fopen(b[i],"r");
			while(fscanf(f,"%c",&ch)!=EOF)
			{
				if(ch=='\n') num++;
				if(ch=='\n' && E==1) 
					printf("%c",'$');
				printf("%c",ch);
				if(ch=='\n' && n==1)
					printf("    %d ",num);
			}
		}
	}
	printf("\n");
}
