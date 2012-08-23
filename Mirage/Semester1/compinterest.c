#include<stdio.h>
main()
{
float p,n,a;
scanf("%f%f",&p,&n);
a=p;
while(n!=0)
{
a=(a+((a*12)/100)-(p/10));
 n=n-1;
}
printf("%f",a);
}
