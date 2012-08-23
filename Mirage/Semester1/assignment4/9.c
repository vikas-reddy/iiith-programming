#include<stdio.h>
main()
{
	int i=0,s=0,j=0,k=0,t=0,s1=0;
	char c,a[1000],b[1000],file1[100],file2[100];
	FILE *f1,*f2;
	scanf("%s%s",file1,file2);
	f1=fopen(file1,"r");
	f2=fopen(file2,"r");
	while(fscanf(f1,"%c",&c)!=EOF)
	{
		switch(c)
		{
			case '/':if(s==2) {s=0;s1=0;}
				 else if(s==0||s==1) s++;
				 	break;
			case '*':if(s==1) {s=2; s1=1;}
			         if(s==0) {a[i]='*';i++;}
				 if(s==2) s=2;
				 break;
			case '\n':
				  if(s1==1) s=2;
				  else if(s==2) s=0;
				  break;	  
			case ' ':case '\t': break;
			default :if(s==0) { a[i]=c; i++; }
				 if(s==1) 
				 {
					 a[i]='/';  i++;
					 a[i]=c;  i++;
					 s=0;
				 }
				 if(s==2) s=2;break;
		}
	}
//	for(j=0;j<i;j++) printf("%c",a[j]);printf("\n");

	while(fscanf(f2,"%c",&c)!=EOF)
	{
		switch(c)
		{
			case '/':if(s==2) {s=0;s1=0;}
				 else if(s==0||s==1) s++;
				 p
				 	break;
			case '*':if(s==1){ s=2;s1=1;}
			         if(s==0) {b[k]='*';k++;}
				 if(s==2) s=2;
				 break;
			case '\n':
				  if(s1==1) s=2;
				  else if(s==2) s=0;
					  break;
			case ' ':case '\t': break;
			default :if(s==0) { b[k]=c; k++; }
				 if(s==1) 
				 {
					 b[k]='/';  k++;
					 b[k]=c;  k++;
					 s=0;
				 }
				 if(s==2) s=2;break;
		}
	}
//	for(j=0;j<k;j++) printf("%c",b[j]);printf("\n");
    	if(i!=k) printf("NO BOTH ARE ORIGINAL\n");
	else
	{
		for(j=0;j<i;j++)
		{
			if(a[j]!=b[j]){printf("NO BOTH ARE ORIGINAL\n");break;}
			else t++;
		}
		if(t==i) printf("YES\n");
	}
}






























	
