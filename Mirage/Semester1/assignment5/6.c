#include<stdio.h>
main()
{
	int n;
	float a[101],k,t;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++) scanf("%f",&a[i]);
	scanf("%f",&k);
	a[n]=k;
	for(i=0;i<n+1;i++)
	{
		for(j=i;j<n+1;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n+1;i++) printf("%f ",a[i]);printf("\n");
}
