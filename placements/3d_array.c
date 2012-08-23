#include<stdio.h>

int main()
{
	int arr[3][2][4] = {1,2,3,4,5,6,7,8,
			    9,10,11,12,13,14,15,16,
			    17,18,19,20,21,22,23,24};

	//printf("sizeof(arr)=%d\nsizeof(*arr)=%d\nsizeof(**arr)=%d\nsizeof(***arr)=%d\n",
		//	sizeof(arr), sizeof(*arr), sizeof(**arr), sizeof(***arr));

	printf("%d\n", *(*(*(arr+2)+1)+ 2));
	return 0;
}
