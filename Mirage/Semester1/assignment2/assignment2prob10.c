#include<stdio.h>
#include<math.h>
main()
{
	float x1,y1,x2,y2,x3,y3,x4,y4,A1,A2,A3,B,A;
	scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	A1=fabs(x4*y2-x2*y4+x2*y3-x3*y2+x3*y4-x4*y3);
	A2=fabs(x4*y3-x3*y4+x3*y1-x1*y3+x1*y4-x4*y1);
	A3=fabs(x4*y1-x1*y4+x1*y2-x2*y1+x2*y4-x4*y2);
	A= fabs(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3);
	B=A1+A2+A3;
	if(A==B)	
 	     	printf("YES");	 
	else
	      	printf("NO"); 

}

 	
