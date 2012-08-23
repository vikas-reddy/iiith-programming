#include<stdio.h>
#include<math.h>
float AM( float a[])
{
	int i=0;
	float sum=0;
	for(i=0;i<10; sum=sum+a[i] , i++);
	sum=sum/10;
	return sum;
}
float GM(float a[])
{
	int i=0;
	float p=1;
	for(i=0;i<10;  p=p*a[i] , i++);
	return ( pow(p,1/10));
}
float HM(float a[])
{
	int i=0;
	float s=0;
	for(i=0;i<10; s=s+(1/a[i]),i++);
	s=s/10;
	return (1/s);
}
main()
{
	float a[10];
	int i=0;
	for(i=0 ; i<10 ; scanf("%f",&a[i]), i++);
	printf("AM=%f\nGM=%f\nHM=%f\n",AM(a),GM(a),HM(a));
}
	
	
	
