#include<stdio.h>
main()
{
	int n,max=0,index=0,i,j,k,h=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{ b[i]=0;	scanf("%d",&a[i]);}
	b[0]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				for(k=0,max=0;k<i;k++)
				{
					if(max<b[k])
					{  max=b[k]; index=k;  }
				}
				b[h]=b[index]+1;h++; break;
			}
		}
	}
/*	for(i=0,max=0;b[i]!=0;i++)
	{    printf("%d\n",b[i]);
		if(max<b[k])
		{  max=b[k];  index=k;  }
		
	}*/
	for(i=0;i<h;printf("%d\n",b[i]),i++);
}
