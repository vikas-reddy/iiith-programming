#include<stdio.h>
#include<stdlib.h>

int main()
{
	union U{
		int x;
		char y;
		float z;
	} un1, un2;

	printf("sizeof(U) = %d\n", sizeof(union U));

	un1.x = 100;
	//un1.y = 'V';
	//un1.z = 200.300;

	printf("%d %c %f\n", un1.x, un1.y, un1.z);
	return 0;
}
