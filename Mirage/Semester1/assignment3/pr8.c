#include<stdio.h>
main()
{
	FILE *f;
	char c,file[100];
	int lines=0,words=0,charec=0;
	scanf("%s",file);
	f=fopen(file,"r");
	c=fgetc(f);
	while(c!=EOF)
	{
		if(c=='\n')
		{
			lines++;
		}
		if((c=='\n')||(c==' ')||(c=='\t'))
		{
			words++;
			c=fgetc(f);
			if((c=='\n')||(c==' ')||(c=='\t'))
			{	
				words--;
			}
		}
		else
		{
			c=fgetc(f);
		}
		charec++;
	}
			printf("  %d  %d  %d  %s",lines,words,charec,file);
}
			
