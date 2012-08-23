#include<stdio.h>
main()
{
	int i=0,n=0,j=0,k=0,l=0,x[100],y[50],mode=0,max=0,t=0,mi=0;
	FILE *f;
	char string[100];
	float median,mean;
	scanf("%s",string);
        f=fopen(string,"r");
	for(i=0;i<100;i++)
	{
	   fscanf(f,"%d",&x[i]);     
	}
	for(j=0;j<51;j++)
	       	y[j]=0;
	for(i=0;i<100;i++)
	{
		for(j=i;j<100;j++)
		{
			if(x[i]>x[j])
			{
				t=x[i]; x[i]=x[j]; x[j]=t;
			}
		}
	}
	for(i=0;i<100;i++)
	{
		mean=mean+x[i];
	}
	mean=mean/100.0;
	median=(x[49]+x[50])/2.0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<51;j++)
		{
			if(x[i]==j)    
			       	y[j]++;
		}
	}
	max=0;
	for(i=1;i<51;i++)
	{
		if(max<y[i])
		{	max=y[i];
			mi=i;
		}
	}
	//for(j=0;j<51;j++)printf("%d %d-",j,y[j]);
	printf("%.2f\n%.2f\n%d\n",mean,median,mi);
}
