#include<stdio.h>
#include<math.h>
main()
{
	int p;
	float n;
	char c,file[100];
	FILE *f;
	scanf("%d %s",&p,file);
	f=fopen(file,"r");
	while(fscanf(f,"%c",&c)!=EOF)
	{
		if(c>='0'&&c<='9')
		{
			fseek(f,-1,SEEK_CUR);
			fscanf(f,"%f",&n);
			printf("%.2f",n*(1+p/100.0));
		}
		else 
		{
				 printf("%c",c);
		}
	}
}	
