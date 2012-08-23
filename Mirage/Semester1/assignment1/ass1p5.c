#include<stdio.h>
#include<math.h>
main(){
float x1,y1,x2,y2,x3,y3,x4,y4,m1,m2,l1,l2,l3,l4;
scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
m1=(y2-y1)/(x2-x1);
m2=(y4-y3)/(x4-x3);
l1=(y3-y1)-m1*(x3-x1);
l2=(y4-y1)-m1*(x4-x1);
l3=(y1-y3)-m2*(x1-x3);
l4=(y2-y3)-m2*(x2-x3);
if ((l1/l2<0)&&(l3/l4<0))
  printf("yes\n");
else printf("no\n");
}
