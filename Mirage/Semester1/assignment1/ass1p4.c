#include<stdio.h>
main(){
int m,n,a=0;
scanf("%d%d",&m,&n);
if ((m<1)||(m>8)||(n<1)||(n>8))
 printf("no such square exists");
else
{  
   if((m-1)>0&&(n-2)>0) a++;
   if((m-2)>0&&(n-1)>0) a++;
   if((m+1)<=8&&(n-2)>0) a++;
   if((m+2)<=8&&(n+1)<=8) a++;
   if((m+2)<=8&&(n-1)>0) a++;
   if((m+1)<=8&&(n+2)<=8) a++;
   if((m-2)>0&&(n+1)<=8) a++;
   if((m-1)>0&&(n+2)<=8) a++;
}
printf("number of ways=%d\n",a);
}


























