#include<stdio.h>
main(int a,char **b)
{
	int l=0,k=0,r=0,o=0,e=0,d[10],s=0,j,i;
	char ch,str[4000];
	for(i=1 ; i<a ; i++)
	{
		if( b[i][0]=='-')
		{
			for(j=1 ; b[i][j]!='\0' ; j++)
			{
				if(b[i][j]=='l') l=1;
				if(b[i][j]=='r') r=1;
				if(b[i][j]=='o') o=1;
				if(b[i][j]=='e') e=1;
			}
		}
	}
	for(i=1 ; i<a ; i++)
	{
		if(b[i][0]!='-')
		{
			FILE *f=fopen(b[i],"r");
			s=0;
			while(fscanf(f,"%c",&ch)!=EOF)
			{
				str[s]=ch; s++; 
			}
			if(r==0)
			{
				for(j=0 ; j<s ; j++)
				{
					if(o==0 && e==0 )
					{
						if(l==0)   			     printf("%c",str[j]);
						if(l==1 && str[j]!='\n')  	     printf("%c",str[j]);
					}
					if(o==1)
					{
						if(j%2==0)
						{
							if(l==1 && str[j]!='\n')     printf("%c",str[j]);
							else                         printf("%c",str[j]);
						}
						else if(str[j]=='\n' && l==0 )  	     printf("%c",str[j]);
					}
					if(e==1)
					{
						if(j%2==1)
						{
							if(l==1 && str[j]!='\n')     printf("%c",str[j]);
							else                         printf("%c",str[j]);
						}
						else if(str[j]=='\n' && l==0  )  printf("%c",str[j]);
					}
				}
			}
			else
			{
				for(j=s-1 ; j>=0 ; j--)
				{
					if(o==0 && e==0 )
					{
						if(l==0)    			printf("%c",str[j]);
						if(l==1 && str[j]!='\n') 	printf("%c",str[j]);
					}
					if(o==1)
					{
						if(j%2==0)
						{
							if(l==1 && str[j]!='\n')printf("%c",str[j]);
							else                    printf("%c",str[j]);
						}
						else if(str[j]=='\n' && l==0 )   printf("%c",str[j]);

					}
					if(e==1)
					{
						if(j%2==1)
						{
							if(l==1 && str[j]!='\n')printf("%c",str[j]);
						}
						else                    printf("%c",str[j]);
					}
					else if(str[j]=='\n' && l==0 )   printf("%c",str[j]);
				}
			}
		}
	}		
	printf("\n");
}


