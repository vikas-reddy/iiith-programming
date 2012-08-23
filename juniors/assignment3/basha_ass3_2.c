#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
	char ch[1000];
	int i=0,j=0,num_flag=0,state=0,flag=0;
	float num=0;
	scanf("%[^\n]",ch);
	char *p;
	p = strtok(ch," ");
	while(p!=NULL)
	{
		i=0;
		flag=0;
		num=0;
		num_flag=0;
		while(p[i]!='\0')
		{
			if(p[i]=='.')
				flag++;
			if((p[i]>='0' && p[i]<='9'))
				state=1;
			else
			{
				printf("%s",p);
				flag=0;
				state=0;
				break;
			}
			i++;
		}
		if(flag<=1 && state==1 && p[i-1]!='.')
		{
			flag=0;
			state=0;
			num = atof(p);
//			for(j=0;j<i;j++)
//			{
//				num=num*10.0+(p[j]-'0');
//			}
			printf("%.2f",num*1.12);
		}
		p = strtok(NULL," ,");
		if(p!=NULL)
			printf(" ");
		else
			printf("\n");
	}
}
