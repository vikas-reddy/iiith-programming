#include<stdio.h>
#include<math.h>
main()
{
int d1,m1,y1,d2,m2,y2,days;
scanf("%d%d%d%d%d%d",&d1,&m1,&y1,&d2,&m2,&y2);
if((d1<=30)&&(d2<=30)&&(m1<=12)&&(m2<=12))
 {days=abs((d1-d2)+(m1-m2)*30+(y1-y2)*360)-1;
  printf("%d\n",days);}
else printf("such a day does'nt exist\n");
}
