#include<stdio.h>
main()
{
	int i,j,t,a[10],min,minindex;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<9;i++)
	{
		min=a[i];
		minindex=i;
		for(j=i+1;j<10;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				minindex=j;
			}
		}	
			t=a[i];
			a[i]=a[minindex];
			a[minindex]=t;
		
	}
	for(i=0;i<10;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}
		
			
			
	         	
