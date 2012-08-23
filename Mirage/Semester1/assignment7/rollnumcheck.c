#include<stdio.h>
main(int a,char **b)
{
	int i=0,j=0,n=0,num=0,k=0,state=0;
	char ch;
	for(i=1 ; i<a ; i++)
	{
		if( b[i][0]>='0' && b[i][0]<='9')
		{
			for(j=0 ; b[i][j]!='\0' ; j++)	  n=n*10 + b[i][j]-'0';
		}
		else k=i;
	}
	FILE *f=fopen(b[k] , "r");
	while(fscanf(f,"%c",&ch)!=EOF)
	{
		if(ch>='0' && ch<='9')
		{
			fseek(f,-1,SEEK_CUR);
			fscanf(f,"%d",&num);
			if(n==num)   {  state=1;  break;  }
		}
	}
	if(state==1)   printf("YES\n");
	else           printf("NO\n");
}
			
		

				


