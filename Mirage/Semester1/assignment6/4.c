#include<stdio.h>
main()
{
	char file[100],a[100][100],temp,ch;
	int i=0,j=0,k=0;
	FILE *f=fopen(file,"r");
	scanf("%s",file);
	for(; fscanf(f,"%c",&ch)!=EOF ;)
	{
		if(ch!='\0') {a[i][j]=ch; j++;}
		if(ch=='\n') {a[i][j]='\0'; i++; j=0;}
	}
	for(i=0;i<100;i++)
	{
		for(j=i+1;j<100;j++)
		{
			for(k=0 ; a[i][k]==a[j][k] && k<100 ; k++);
			if(k<100) 
			{
				if(a[i][k]>a[j][k])
				{
					for(k=0; k<100 ;k++)
					{  
						temp=a[i][k];
						a[i][k]=a[j][k];
						a[j][k]=temp; 
					}
				}
			}
		}
	}
	for(i=0 ; i<100 ; printf("%s",a[i]),i++); 

}

