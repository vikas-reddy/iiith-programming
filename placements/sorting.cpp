#include<iostream>
#include<stdlib.h>
using namespace std;

void bubble_sort(int *array, int array_length)
{
	int i=0, j=0, temp=0;
	for(i=0; i<array_length; i++)
	{
		for(j=0; j<array_length-i-1; j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return;
}

void selection_sort(int *array, int array_length)
{
	int i=0, j=0, temp=0, min_index=0;
	for(i=0; i<array_length-1; i++)
	{
		min_index = i;

		for(j=i+1; j<array_length; j++)
			if(array[j] < array[min_index])
				min_index = j;

		if(min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
		}
	}
	return;
}

void insertion_sort(int *array, int array_length)
{
	int i=0, j=0, k=0, temp=0;
	for(i=1; i<array_length; i++)
	{
		temp = array[i];
		for(j=i-1; (j>=0) && (array[j] > temp); j--)
			array[j+1] = array[j];
		array[j+1] = temp;
	}
	return;
}

void heapify(int *array, int array_length)
{
	return;
}

int main()
{
	int arr[20];

	for(int i=0; i<20; arr[i]=rand()%1000, cout << arr[i] << " ", i++); cout << endl;
	insertion_sort(arr,20);
	for(int i=0; i<20; cout << arr[i] << " ", i++); cout << endl;
}
