#include<stdio.h>

main()
{
	char c;
	FILE *f1,*f2;
	f1=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	while(fscanf(f1,"%c",&c)!=EOF)
	{
		if ((c>=65)&&(c<=90))
			fprintf(f2,"%c",c+32);
		else 
		{     if((c>=97)&&(c<=122))
			    fprintf(f2,"%c",c-32);
		      else 
			    fprintf(f2,"%c",c);
		}

	}	
}
