#include<stdio.h>
main()
{
	int s=0,cnt=0,s1=0,s2=0,s3=0;
	char c,fn[100];
	FILE *f;
	scanf("%s",fn);
	f=fopen(fn,"r");
	while(fscanf(f,"%c",&c)!=EOF)
	{
		switch(c)
		{
			case 'a':case 'A':if(s==0) {s=1;s1=1;}
				 	  else s=-1;		break;
			case 'n':case 'N':if(s==1) {s=2;s2=1;}
				 	  else s=-1;		break;
			case 't':case 'T':if(s==0) s=1;
	         			  else s=-1;		break;
			case 'h':case 'H':if(s==1) s=2;
				 	  else s=-1;		break;
			case 'e':case 'E':if(s==2) {s=3;s3=1;}
				 	  else s=-1;		break;
			case ' ':case '\t':case '?':case '\n':case '.':case ',':  
					  if((s1==1||s2==1||s3==1)&&s!=0&&s!=-1)
					  { 
					    	s=0;s1=0;s2=0;s3=0;
					    	cnt++;
					  }
					  s=0;              
					  			break;
			default :s=-1;				break;
		}
	}
	printf("%d\n",cnt);
}
