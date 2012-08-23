#include<stdio.h>
main()
{
	char c;
	int k=0;
	FILE *f1,*f2;
	f1=fopen("input.txt","r");
	f2=fopen("output.txt","w");
	while (fscanf(f1,"%c",&c)!=EOF) k++;
	while(k>=0)
	{	
		fseek(f1,k,SEEK_SET);
		fprintf(f2,"%c",fgetc(f1));
		k--;
	}
}	
