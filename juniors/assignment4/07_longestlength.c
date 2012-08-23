/*
 * Program to find the cycle of longest length given an array of numbers
 *
 */

#include<stdio.h>
#include<stdlib.h>

main()
{
	int n=0, i=0;
	while(scanf("%d", &n) != EOF)
	{
		int arr[n];
		for(i=0; i<n; scanf("%d", &arr[i]), i++);

		for(i=0; i<n; printf("%d ", arr[i]), i++);
		printf("\n");
		del [] arr;
	}
	return;
}
