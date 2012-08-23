#include<stdio.h>
main(int argc,char *argv[])
{
	FILE *f;
	char c;
	int lines=0,words=0,charec=0;
	//anf("%s",file);
	f=fopen(argv[1],"r");
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
			printf(" %d  %d %d %s\n",lines,words,charec,argv[1]);
}
			
