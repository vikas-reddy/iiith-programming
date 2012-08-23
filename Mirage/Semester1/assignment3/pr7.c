#include<stdio.h>
main()
{                                                                                       
	int t=0,s=0;
	char c,file[100];
	FILE *f;
	scanf("%s",file);	
	f=fopen(file,"r");
"	while(fscanf(f,"%c",&c)!=EOF)
	{
		switch(c)
		{
			case 'i' : case 'I' :   if(s==0||s==1||s==2)
							s++;
						else    s=-1;                  break;
			case 't' : case 'T' :   if(s==3)
							s++;
						else    s=-1;	               break;
			case ' ' : case '\n' : case '\t' : case '.'  : case ',' :         if(s==-1) s=0;   
												  else if(s==4) {t++;s=0;}								                            break;	

			default  : s=-1;                 
		}
	}
	printf("%d\n",t);
}	
