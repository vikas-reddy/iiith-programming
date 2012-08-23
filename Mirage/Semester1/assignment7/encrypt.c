#include<stdio.h>
#include<math.h>
void Encrypt(int *a,int n)
{
	int b[n][32],t[8],i=0,j=0,k=0;
	for(k=0 ; k<n ; k++)
	{
		for(j=0,i=31 ; i>=0 ; i--,j++)
			b[k][i]= ( (a[k]>>j) & 1 );
	}   
	for(k=0 ; k<n ; k++)
	{
		for(i=24,j=0 ; i<32 ; i++,j++)
			t[j]=b[k][i];
		for(i=31 ; i>=8 ; i--)
			b[k][i]=b[k][i-8];
		for(i=0 ; i<8 ; i++)
			b[k][i]=t[i];
	}
	for( k=0 ; k<n ; k++)
	{
		a[k]=0;
		for(i=31 ; i>=0 ; i--)
		{
			a[k]=a[k]+pow(2,(31-i))*b[k][i];
		}
	}
	for(i=0 ; i<n ; printf("%d\n",a[i]), i++);
}
void Decrypt(int *a,int n)
{
	int b[n][32],i=0,t[8],j=0,k=0;
	for(k=0 ; k<n ; k++)
	{
		for(j=0,i=31 ; i>=0 ; i--,j++)
			b[k][i]= ( (a[k]>>j) & 1 );
	}       for(k=0 ; k<n ; k++)
	{
		for(i=0 ; i<8 ; i++)
			t[i]=b[k][i];
		for(i=0 ; i<24 ; i++)
			b[k][i]=b[k][i+8];
		for(i=24,j=0 ; i<32 ; i++,j++)
			b[k][i]=t[j];
	}

	for( k=0 ; k<n ; k++)
	{
		a[k]=0;
		for(i=31 ; i>=0 ; i--)
		{
			a[k]=a[k]+pow(2,(31-i))*b[k][i];
		}
	}
	for(i=0 ; i<n ; printf("%d\n",a[i]), i++);
}	
			       	
	main()
{
	int F,n,i=0,j=0,k=0;
	scanf("%d%d",&F,&n);
	int a[n];
	for( i=0 ; i<n ; scanf("%d",&a[i]), i++ );
	if(F==0)  Encrypt(a,n);	
	else      Decrypt(a,n);
}		
		
		

