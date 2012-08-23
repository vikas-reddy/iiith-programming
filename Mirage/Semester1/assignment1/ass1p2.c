#include<stdio.h>
#include<math.h>
main()
{
float a,b,c,s1,s2,soln,re,img;
scanf("%f%f%f",&a,&b,&c);
if(a!=0)
 {
      if((b*b-4*a*c)>=0)
      { s1=(-b+sqrt(b*b-4*a*c))/(2*a);
        s2=(-b-sqrt(b*b-4*a*c))/(2*a);
        printf("s1=%f\ns2=%f\n");
      }
      else
      { re=(-b)/(2*a);
        img=(sqrt(4*a*c-b*b))/(2*a);
        printf("cs1=%f+i%f\n",re,img);
	printf("cs2=%f-i%f\n",re,img);
      }
 }
else
 {  if(b!=0)
    {soln=-(c/b);
     printf("soln=%f\n",soln);
    }
    else printf("no such quadratic equation exists\n");
 }
}
