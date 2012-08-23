#include <iostream>
#include <stdlib.h>
using namespace std;

// Declaring a double dimension Global variable .
int **arr;

void memallocate(int num)
// Memory allocating.
{
	arr = new int*[num];
	for( int i=0 ; i<num ; i++)
		arr[i] = new int[num];
}


void bfs(int num,bool *flag,int node,int parent)
{
	for( int i=0; i<num ; i++ )
	{
		if(arr[node][i] && i!=parent)
		{
			if( flag[i])
			{
					cout << "NO\n";
					exit(0);
			}
			else
			{
				flag[i] = true;
				bfs(num,flag,i,node);
			}
		}
	}
	return;
}

int main()
{
	int num;
	cin >> num;
	memallocate(num);
	bool flag[num];
	
	for( int i=0 ; i<num ; flag[i]=false,i++ )
		for( int j=0 ; j<num ; cin>>arr[i][j] , j++ );

	flag[0] = true;
	bfs(num,flag,0,0);
	cout << "YES\n";
	return 0;
}
