#include <iostream>
#include<stdlib.h>
using namespace std;

void merge(int *src1,int *src2,int *dest,int size_a,int size_b)
{
	int ptr_a=0,ptr_b=0,pos=0;
	for(    ;  (ptr_a !=size_a-1) &&  (ptr_b !=size_b-1)  ;  pos++ )
	{
		if( src1[ptr_a] < src2[ptr_b] )
		{
			dest[pos] = src1[ptr_a];
			ptr_a++;
		}
		else
		{
			dest[pos] = src2[ptr_b];
			ptr_b++;
		}
	}
	if( ptr_a!=size_a-1 )
		for(   ; ptr_a<size_a ; dest[pos]=src1[ptr_a] , ptr_a++,pos++ );
	else if( ptr_b!=size_b-1)
		for(   ; ptr_b<size_b ; dest[pos]=src2[ptr_b] , ptr_b++,pos++ );
	return;
}
	
/*int main()
{
	int n;
	cin >> n;
	int a[n],b[n],c[2*n];
	for(int i=0 ; i<n ; cin>>a[i], i++ );
	for(int i=0 ; i<n ; cin>>b[i], i++ );
	
	merge(a,b,c,n,n);
	
	for( int i=0 ; i<2*n ; cout<<c[i]<<" ",i++ );
	cout << endl;
	return 0;
}*/

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for ( int i=0 ; i<n ; arr[i]=rand()%1000 , i++ );
	for( int i=0 ; i<n ; i*=2 )
	{
		merge(
}	
