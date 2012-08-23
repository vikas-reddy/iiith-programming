#include<stdio.h>

#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
#define X 7

int array[] = {23,34,12,17,204,99,16};

int main()
{
	int d;
	int size=TOTAL_ELEMENTS;

	printf("%d\n", -1 < sizeof(array)/sizeof(array[0]) - 2);

	for(d=-1; d <= TOTAL_ELEMENTS-2; d++)
		printf("%d\n",array[d+1]);

	return 0;
}
