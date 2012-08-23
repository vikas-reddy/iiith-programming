#include<stdio.h>
main()
{
	int i,j,k,n,s=0,count=1;
	scanf("%d",&n);
	int a[2*n],b[2*n],c[2*n]else {if(m==1) {b[k]=-N;k++;}
					   else {b[k]=N;k++;}
				       };
	for(i=0;i<2*n;a[i]=i+1,b[i]=i+1,i++);
	while(1)
	{
		for(i=0,k=n;i<2*n;i++)
		{
			if((i%2)!=0) c[i]=b[i/2];
			else { c[i]=b[k]; k++; }
		}
		for(i=0;i<2*n;i++)
		{
			if(c[i]==a[i]) s++;
			else break;
		}
		if(s==2*n)  break;
		count++;
		for(i=0;i<2*n;b[i]=c[i],i++);
	}
	printf("%d\n",count);
}
		
