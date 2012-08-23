/*mutiply two numbers*/
#include<stdio.h>
#include<string.h>
main()
{
	char c1[25],c2[25];
	while(scanf("%s %s",c1,c2)!=EOF){
	int a[25],b[25],ans[25][50],i,j,k1,k2,p,q,add,pro,t,sum,sss[51],k;
	for(i=0;i<25;i++)
		for(j=0;j<50;j++)
			ans[i][j]=0;
	k1=strlen(c1);
	k2=strlen(c2);
	for(i=0;i<k1;i++)
		a[i]=c1[i]-'0';
	for(i=0;i<k2;i++)
		b[i]=c2[i]-'0';
	i=0;
	p=k1,q=k2;
	for(i=0;i<k2;i++)
	{
		add=0;
		k1=p;
		for(j=k1+k2-1; j>k1+k2-1-i; j--);
		while(k1!=0)
		{
			pro=a[k1-1]*b[k2-i-1]+add;
			ans[i][j]=pro%10;
			add=(pro-ans[i][j])/10;
			k1--;
			j--;
		}
		ans[i][j]=add;
	}
	sum=0,add=0;
	for(j=p+q-1;j>=0;j--)
	{
		sum=0;
		for(i=0;i<q;i++)
		{
			sum=sum+ans[i][j];
		}
		sss[j]=(sum+add)%10;
		add=(sum+add)/10;
	}
	for(j=0;j<p+q-1;j++)
		if(sss[j]!=0)
			break;
	for(i=j;i<p+q;i++)
		printf("%d",sss[i]);
	printf("\n");}
}
