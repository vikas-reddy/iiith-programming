#include <iostream>
#include <stdlib.h>
using namespace std;

int partition(int array[],int f,int l)
{
	int pivot=array[f],low=f,high=l,temp=0;
	while(low < high)
	{
		for(     ;   array[low]  <= pivot   &&  low  <l  ; low++  );
		for(     ;   array[high] >  pivot   &&  high >f  ; high-- );
		if( low < high )
		{
			temp = array[low];
			array[low] = array[high];
			array[high] = temp;
		}
	}
	array[f] = array[high];
	array[high] = pivot;
	return high;
}
	
void quicksort(int x[], int first, int last) 
{
	if( first >= last )
		return;
	int pivIndex = 0;
	pivIndex = partition(x,first, last);
	quicksort(x,first,(pivIndex-1));
	quicksort(x,(pivIndex+1),last);
}



int main()
{
	int n;
	cin >> n;
	int arr[n];
	for( int i=0 ; i<n ; arr[i]=rand()%1000 , i++ );
	quicksort(arr,0,n-1);
	for( int i=0 ; i<n ;cout<<arr[i]<<" " , i++ );
	cout << endl;
	return 0;
}
	
