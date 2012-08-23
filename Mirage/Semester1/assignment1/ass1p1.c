#include<stdio.h>
#include<math.h>
main()
{
float a,b,c,d,distance;
scanf("%f%f%f%f",&a,&b,&c,&d);
distance=sqrt(pow(a-c,2)+pow(b-d,2));
printf("distance=%f units",distance);
}
