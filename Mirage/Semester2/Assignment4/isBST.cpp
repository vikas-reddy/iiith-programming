#include <iostream>
using namespace std;


int bag=0;

int pow(int a,int b)
{
	int prd=1;
	for( int i=0 ; i<b ; prd=prd*a , i++ );
	return prd;
}
int main()
{
	int height,a,b;
	cin >> height;
	
	int num=pow(2,height),arr[pow(2,height)];
	
	for( int i=1 ; i<num ; cin>>arr[i] , i++ );

	
	for( int i=1 ; i<((num)/2) ; i++ )
	{
		a = 1;
		b = 1;
		if( arr[2*i]!=-1  && arr[2*i]>=arr[i] )
			a = 0;
		if( arr[2*i+1]!=-1 && arr[2*i+1]<=arr[i])
			b = 0;
	//	if( (arr[2*i]!=-1 && arr[i]<arr[2*i]) &&
	//		(arr[2*i+1]!=-1 && arr[i]>arr[2*i+1]) )
		if( !a || !b )
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}		
