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
	for( v=0,state=0  ; v<=m || v <=n ;   )
	{
		state = 0;
		if(mat[x][y] == 0) 
		{
			cout<<x<<" "<<y<<endl;
			break;
		}
		for( int i=y-v   ;x-v>=0 &&  state==0 && i<=y+v;   i++ )
			if( i>=0 && i<n && mat[x-v][i] == 0 ) 
			{
				x = x-v;  
				y = i;
				state = 1 ;
				break;
			}
		for( int i=y-v   ;x+v>=0 && state==0 && i<=y+v;    i++ )
			if( i>=0 && i<n &&  mat[x+v][i] == 0 ) 
			{
				x = x+v;
				y = i;
				state = 1 ;
				break;
			}
		for( int i=x-v+1 ; y-v>=0 &&  state==0 && i<x+v;   i++ )
			if( i>=0 && i<m &&  mat[i][y-v] == 0 ) 
			{
				x = i;
				y = y-v;
				state = 1 ;
				break;
			}
		for( int i=x-v+1 ; y+v>=0 &&  state==0 && i<x+v;   i++ )
			if( i>=0 && i<m &&   mat[i][y+v] == 0 ) 
			{
				x = i;
				y = y+v;
				state = 1 ;
				break;
			}
		if( state == 0 ) 
			v++;
	}
}

