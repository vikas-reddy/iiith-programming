#include<stdio.h>
#define SUM(a,b) (a)+(b)
#define MULT(a,b) a*b

main()
{
	int a=2, b=3, ans=0;
	ans = SUM( MULT(a, b), b)  - SUM( b,MULT(b,a));
	printf("ans = %d\n", ans);
	return 0;
}
