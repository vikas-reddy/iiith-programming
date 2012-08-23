#include<stdio.h>
#include<math.h>
main()
{
	int i=0,j=0,k=0,n=0,m=0,t=0,l=0,s=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0 ; i<n ; scanf("%d",&a[i]),i++);
	scanf("%d",&m);
	for(i=0 ; i<n ; i++)
		for(j=i+1 ; j<n ; j++)
		{
			if(a[i]>a[j])
			{ t=a[i];a[i]=a[j]; a[j]=t;}
		}
	for(i=pow(2,n)-1 ; i>=0 ; i--)
	{	
		for(k=n,t=i,j=0 ; k>=1 ; k--)
		{
			if((t>>(k-1))&1==1) 
			{ b[j]=a[n-k] ;j++; }
		}
		for(l=0,s=0 ; l<j ; s=s+b[l],l++);
		if(s==m && j==5) 
		{	 for(l=0 ; l<j ; l++)  printf("%d ",b[l]);
				printf("\n");
		}
	}
}
		
			
