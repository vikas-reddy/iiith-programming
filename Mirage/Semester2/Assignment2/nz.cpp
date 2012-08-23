#include <iostream>
using namespace std;

int main()
{
	int m,n,x,v=1,X,y,Y,state=0;
	cin >> m >> n;
	int mat[m][n];
	for( int i=0 ; i < m ; i++ )
	       for( int j=0 ; j < n ; cin >> mat[i][j] , j++ );
	cin >> X >> Y ;
	x=X ; y=Y;
	for(;1;)
	{
		state = 0;
		if(mat[x][y] == 0) 
		{
			cout<<x<<" "<<y<<endl;
			break;
		}
		if(  x+v<m  &&           mat[x+v][y]  ==0 ) { state = 1; x=x+v       ; }
		if(  x+v<m  && y+v<n  && mat[x+v][y+v]==0 ) { state = 1; x=x+v; y=y+v; }
		if(            y+v<n  && mat[x][y+v]  ==0 ) { state = 1;        y=y+v; }
		if(  x-v>=0 && y+v<n  && mat[x-v][y+v]==0 ) { state = 1; x=x-v; y=y+v; }
		if(  x-v>=0 &&           mat[x-v][y]  ==0 ) { state = 1; x=x-v       ; }
		if(  x-v>=0 && y-v>=0 && mat[x-v][y-v]==0 ) { state = 1; x=x-v; y=y-v; }
		if(            y-v>=0 && mat[x][y-v]  ==0 ) { state = 1;        y=y-v; }
		if(  x+v<m  && y-v>=0 && mat[x+v][y-v]==0 ) { state = 1; x=x+v; y=y-v; }
		if( state == 0 ) 
		{
			v++;
		}
	}
}

