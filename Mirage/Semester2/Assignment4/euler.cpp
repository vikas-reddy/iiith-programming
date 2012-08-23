#include <iostream>
using namespace std;

int main()
{
	int num_vertices;
	cin>>num_vertices;
	int mat[num_vertices][num_vertices];

	for( int i=0 ; i<num_vertices ; i++ )
		for( int j=0 ; j<num_vertices ; cin>>mat[i][j] , j++);

	int state=0;
	for( int i=0,s=0 ; i<num_vertices ; i++ )
	{
		for( int j=0 ; j<num_vertices ; j++ )
			if( mat[i][j] )
				s++;
		if( s%2 == 0)
			state =1;
		else
		{
			state = 0;
			break;
		}
	}
	if( state )
		cout << "YES\n";
	else
		cout << "NO\n";
}
