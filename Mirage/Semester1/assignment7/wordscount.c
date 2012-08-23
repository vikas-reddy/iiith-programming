#include<stdio.h>
main(int a, char **b)
{
	int p=0,i,j,e=0,k,c=0,d[10],m=0,g=0,l=0,L=0,w=0;
	int index=0,max=0,maxcnt=0,lines=0,charec=0,words=0;
	int sum[5]={};
	char ch;
	for(i=1 ; i<a ; i++)
	{
		if(b[i][0]=='-')
		{
			for(j=1 ; b[i][j]!='\0' ; j++)
			{
				if(b[i][j]=='c')  c=1;
				if(b[i][j]=='m')  m=1;
				if(b[i][j]=='l')  l=1;
				if(b[i][j]=='L')  L=1;
				if(b[i][j]=='w')  w=1;
			}
		}
		else {  d[p]=i; p++;  }
	}
	for(i=0 ; i<p ; i++)
	{
		FILE *f=fopen(b[d[i]],"r");
		ch=fgetc(f);
		maxcnt=0; j=0; words=0; lines=0; charec=0;
		int state=0;
		e=0;
		while(ch!=EOF)
		{
			if(ch=='\n')
			{
				lines++;
				if(e<maxcnt) e=maxcnt;  
				maxcnt=0;
				state=1;
			}
			if((ch=='\n')||(ch==' ')||(ch=='\t'))
			{
				words++;
				ch=fgetc(f)	;
				if((ch=='\n')||(ch==' ')||(ch=='\t'))
				{
					words--;
				}
			}
			else             
			{
       		        	ch=fgetc(f);
				state=0;
			}
			charec++;
			if(state==1 && ch=='\t') maxcnt=maxcnt+8;	
			else if(state==0 && ch=='\t') maxcnt=maxcnt+4;
			else  {maxcnt++; state=0; }
		}
		sum[0]=sum[0]+lines;
		sum[1]=sum[1]+words;
		sum[2]=sum[2]+charec;
		if(g<e) g=e-1;
		if(m==0 && l==0 && L==0 && w==0 && c==0)
		{
			printf("%3d ",lines);
			printf("%3d ",words);
			printf("%3d ",charec);
			printf("%s\n",b[d[i]]);
		}
		else
		{
			if(l)  printf("%3d ",lines);
			if(w)  printf("%3d ",words);
			if(c)  printf("%3d ",charec);
			if(m)  printf("%3d ",charec);
			if(L)  printf("%3d ",e-1);
			printf("%s\n",b[d[i]]);
		}
	}
	if(p!=1)
	{
		if(l==0 && w ==0 && c==0 && m==0 && L==0)
		{
			printf("%3d ",sum[0]);
			printf("%3d ",sum[1]);
			printf("%3d ",sum[2]);
			printf("total\n");
		}
		else
		{
			if(l)  printf("%3d ",sum[0]);
			if(w)  printf("%3d ",sum[1]);
			if(c)  printf("%3d ",sum[2]);
			if(m)  printf("%3d ",sum[2]);
			if(L)  printf("%3d ",g);
			printf("total\n");
		}
	}
}



