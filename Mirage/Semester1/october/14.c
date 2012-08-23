#include<stdio.h>
main(int argc,char *argv[])
{
	int L=0,n=1,m,W=0,C=0,index=0,charcnt=0,k=0,linecnt=0,wordcnt=0;
	char c;
	for(k=1;k<argc;k++)
	{ 
		if(argv[k][0]!='-') 
		{
			m=k; break;
		}	
	}
	while(index<argc) 
	{
		if(argv[index][0]=='-')
			for(k=1; argv[index][k]!='\0'; k++) 
			{
				if(argv[index][k]=='l') {L=1;n=0;}
				if(argv[index][k]=='w') {W=1;n=0;}
				if(argv[index][k]=='c') {C=1;n=0;}
			}
		index++;
	}
	//if(index==2) m=1;
	//else m=2;
	FILE *f1=fopen(argv[m],"r");
	while(fscanf(f1,"%c",&c)!=EOF )
	{
		charcnt++;
		if(c=='\n') linecnt++;
	}
	if(n==0)
	{
		if(L==1) printf("%d ",linecnt);
		if(W==1) printf("%d ",wordcnt);
		if(C==1) printf("%d ",charcnt);
		printf("%s\n",argv[m]);
	}	
	else printf("%d %d %d %s",linecnt,wordcnt,charcnt,argv[m]);
}
		
		
	
	
