#include<stdio.h>
#include<stdlib.h>
main()
{
	int i=0,s1=0,cnt1=0,y=0,cnt2=0,k=0,j=0,s=0;
	char b[2000],file[100],c,ch,a[2000];
	scanf("%s",file);
	FILE *f=fopen(file,"r");
	while(fscanf(f,"%c",&c)!=EOF)
	{
		switch(c)
		{
			case '/':
				if(y==1) { a[i]=c; i++; }
				else 
				{ 
					if(s==0) s=1;
					else if(s==1) s=0; 
				} 
				break;
			case '*':
				if(y==1) { a[i]=c; i++; }
				else {
					if(s==1) s=2;
					else if(s==2) s=1;
					else { a[i]='*'; i++; }
				}
				break;
			case '"':
				if(s!=2)
				{
					if(y==0)  y=1; 
					else if(y==1)  y=0; 
					a[i]=c; i++;
				} 
				else
				{
					c=fgetc(f);
					while(1)
					{
						c=fgetc(f);
						if(c=='"') break;
					}
					fseek(f,-2,SEEK_CUR);
				}
				break;
			default :
				if(y==1) { a[i]=c; i++; }
				else 
				{
					if(s==0) { a[i]=c; i++; }
					else if(s==1) { a[i]='/' ; i++; a[i]=c ; i++; s=0;}
				}
				break;	 
		}
	}
	FILE *f1=fopen(file,"r");
	while(fscanf(f1,"%c",&ch)!=EOF)  { b[k]=c; k++; }
	y=0;
	for( i=0 ; i<k ;i++)
	{	if(b[i]=='"')
		{
			if(y==0)  y=1; 
			else if(y==1)  y=0; 
		}
		if(y==0)
		{
			if(b[i]=='/' && b[i+1]=='*') cnt1++;
			if(b[i+1]=='/' && b[i]=='*') cnt2++;
		}
	}	
	/*for(j=0 ; j<i ; j++)
	{
		if(y==0)
		{
			if(a[j]=='/' && a[j+1]=='*') cnt1++;
			if(a[j+1]=='/' && a[j]=='*') cnt2++;
		}
	}*/
	printf("%d %d\n",cnt1,cnt2);
	/*if(cnt1!=cnt2) printf("Error\n");
	else for( j=0 ; j<i ; printf("%c",a[j]),j++);
*/}
