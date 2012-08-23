#include<stdio.h>
#include<math.h>
main()
{
	char c,file[100];
	int l,m,n=0;
	FILE *f;
	scanf("%s",file);
	f=fopen(file,"r");
	while(fscanf(f,"%c",&c)!=EOF)
	{       if(c!='\n')
		{
			n=0;
			m=0;
			for(m=7;m>=0;m--)
			{
				l=c&1;
				n=n+l*pow(2,m);
				c=c>>1;
			}
			printf("%c",n);
		}
	}
	printf("\n");
}


