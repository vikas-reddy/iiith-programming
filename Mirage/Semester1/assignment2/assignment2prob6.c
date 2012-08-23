#include<stdio.h>
#include<math.h>
main()
{
	int n,m,a,i=0,j,l;
	scanf("%d",&n);
	l=n;
	while(l!=0)
	{m=l%10;l=(l-m)/10;i++;}
	j=i-1;
	while(j>=0)
	{     a=n/(pow(10,j));
		switch(a)
		{	case 1 :printf("One ");break;
			case 2 :printf("Two ");break;
			case 3 :printf("Three ");break;
			case 4 :printf("Four ");break;
			case 5 :printf("Five ");break;
			case 6 :printf("Six ");break;
			case 7 :printf("Seven ");break;
			case 8 :printf("Eight ");break;
			case 9 :printf("Nine ");break;
		        case 0 :printf("Zero ");break;
		          
                }
	     n=n-a*(pow(10,j));
	     j--;    
	}
}













