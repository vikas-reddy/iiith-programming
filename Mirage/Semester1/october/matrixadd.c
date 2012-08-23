#include<stdio.h>
#include<stdlib.h>
int **ADD(int **a,int **b,int N)
{
	int i=0,j=0,**c;
	/*  Memory Allocation  */
	c=(int **)malloc(N*sizeof(int*));
	for(i=0 ; i<N ; i++)
		c[i]=(int *)malloc(N*sizeof(int));
	/* Calculating */
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			c[i][j]=a[i][j]+b[i][j];
	return(c);
}
int **Transpose(int **a,int N)
{
	int temp,i=0,j=0,**c;
	c=(int **)malloc(N*sizeof(int*));
	for(i=0 ; i<N ; i++)
		c[i]=(int*)malloc(N*sizeof(int));
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
		{
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	return(c);
}

main()
{	
	int i=0,j=0,n=0;
	scanf("%d",&n);
	int **a,**b,**c;
	/*  Memory Allocation  */
	a=(int **)malloc(n*sizeof(int*));
	for(i=0 ; i<n ; i++)
		a[i]=(int *)malloc(n*sizeof(int));
	b=(int **)malloc(n*sizeof(int*));
	for(i=0 ; i<n ; i++)
		b[i]=(int *)malloc(n*sizeof(int));
	/* Scanning  */
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
		{
			scanf("%d",&b[i][j]);
		}
	//c=ADD(a,b,n);
	c=Transpose(a,n);
	printf(" Answer = \n");
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
