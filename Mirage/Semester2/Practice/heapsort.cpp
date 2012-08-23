#include <iostream>
#include <stdlib.h>
using namespace std;

int leftchild(int x)    {	return ( 2*x );          }
int rightchild(int x)   {	return ( 2*x + 1 );      }
int parent(int x)       {       return ( x/2 );          }
void swp(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return;
}



int main()
{
	int j,n;
	cin >> n;
	int arr[n+1];
	for( int i=1 ; i<=n ; cin>>arr[i] , i++ );
	int i,temp;
	for( i=n/2 ; i>0 ; i-- )
	// This 'for' loop is for creating a max-heap in the existing array.
	{
		for( temp=arr[i],j=i ; j <= n ;      )
		{
			if( leftchild(j)<=n )
			{
				if( rightchild(j)<=n )
				{	
					if(temp>arr[leftchild(j)] && temp>arr[rightchild(j)])
						break;
					else if( arr[leftchild(j)] > arr[rightchild(j)] )
					{
						arr[j] = arr[ leftchild(j)];
						j = leftchild(j);
					}
					else
					{
						arr[j] = arr[ rightchild(j)];
						j = rightchild(j);
					}
				}
				else
				{
					if(temp<arr[leftchild(j)])
					{
						arr[j] = arr[leftchild(j)];
						j = leftchild(j);
					}
					break;
				}
				
			}
			else break;
		}
		arr[j] = temp;
	}
	
	for( int last=n ;  last > 1 ; last-- ) 
	// This 'for' loop is for sorting the array .
	{
		swp( &arr[1] , &arr[last] );
		temp = arr[1];
		for( j = 1 ; j<= last-1 ;    )
		{
			if( leftchild(j)<=last-1 )
			{
				if( rightchild(j)<=last-1 )
				{	
					if(temp>arr[leftchild(j)] && temp>arr[rightchild(j)])
						break;
					else if( arr[leftchild(j)] > arr[rightchild(j)] )
					{
						arr[j] = arr[ leftchild(j)];
						j = leftchild(j);
					}
					else
					{
						arr[j] = arr[ rightchild(j)];
						j = rightchild(j);
					}
				}
				else
				{
					if(temp<arr[leftchild(j)])
					{
						arr[j] = arr[leftchild(j)];
						j = leftchild(j);
					}
					break;
				}
				
			}
			else break;
		}
		arr[j] = temp;
	}
	for( int i=1 ; i<=n ; cout<<arr[i]<<" " , i++ );
	cout << endl;
	return 0;
}

