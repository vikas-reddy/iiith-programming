#include<stdio.h>
main()
{
	int i,j,k=0,s=0;
	char a[60],b[60];
	scanf("%[^\n]",a);
	scanf("%s",b);
	for(i=0;a[i]!='\0';)
	{
		for(j=0;b[j]!='\0';j++)
		{
			if(a[i]!=b[j])  s=0;
			else { s=1; break; }
		}
		if(s==0) { a[k]=a[i];k++;i++; }
		if(s==1)  i++;
	}
	for(i=0;i<k;i++) printf("%c",a[i]);printf("\n");
}
