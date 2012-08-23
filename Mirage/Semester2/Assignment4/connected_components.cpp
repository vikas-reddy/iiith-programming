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
			if( !flag[i] )
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
	int num,count=0,x=0,state=1;
	cin >> num;
	memallocate(num);
	bool flag[num];
	
	for( int i=0 ; i<num ; flag[i]=false,i++ )
		for( int j=0 ; j<num ; cin>>arr[i][j] , j++ );
	
	
	while(1)
	{
		for(int i=0 ; i<num ;i++)
		{
			if( !flag[i] )
			{	x=i;
				state =1;
				break;
			}
			else state=0;
		}
		if( !state )
			break;
		if( state )
		{
			flag[x] = true;
			bfs(num,flag,x,x);
			count ++ ;
		}
	}
        cout<< count<<endl;
}
