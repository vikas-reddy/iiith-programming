#include <iostream>
using namespace std;

class graph
{
	private:
		int **mat;
		int num_vertices;
		int **ans;
	public:
		graph(int a)
		{
			mat = new int*[a];
			for(int i=0 ; i<a ; i++ )
				mat[i] = new int[a];
			
			ans = new int*[a];
			for( int i=0 ; i<a ; i++ )
				ans[i] = new int[2];
			num_vertices = a;
			return;
		}
		void insert()
		{
			for( int i=0 ; i<num_vertices ; i++ )
				for(int j=0 ; j<num_vertices ; cin>>mat[i][j] , j++ );
		}
		void Prims()
		{
			int   dist[num_vertices];
			int   prev[num_vertices];
			bool known[num_vertices];
			
			for( int i=0 ; i<num_vertices ; i++ )
			{
				known[i] = false;
				dist[i] = 0;
				prev[i] = -1;
			}
			
			
			int max=0,ptr=0;
			for( int count=0 ; count<num_vertices ; count++ )
			{
				// Updating the dist[] and prev[] arrays
				known[ptr] = true;
				for(int i=0 ; i<num_vertices; i++ )
				{
					if( !known[i] )
						if( mat[ptr][i] > dist[i])
						{
							dist[i] = mat[ptr][i];
							prev[i] = ptr;
						}
				}
				// finding maximum value in the dist[]
				max = 0;
				for(int i=0 ; i<num_vertices ; i++ )
				{
					if( !known[i] )
					{
						if( max<dist[i] )
						{
							max = dist[i];
							ptr = i;
						}
					}
				}
			}
			
			for( int i=0 ; i<num_vertices ; i++ )
			{
				ans[i][0] = i;
				ans[i][1] = prev[i];
			}
			return;
		}
		void print()
		{
			int temp=0;
			for(int i=1;i<num_vertices;i++)
			{
				if(ans[i][0]>ans[i][1])
				{
					temp = ans[i][0];
					ans[i][0] = ans[i][1];
					ans[i][1] = temp;
				}
			}
			for( int j=0 ; j<num_vertices  ; j++ )
			for(int i=1;i<num_vertices-1;i++)
				if(ans[i][0]>ans[i+1][0])
				{
					temp = ans[i][0];
					ans[i][0] = ans[i+1][0];
					ans[i+1][0] = temp;

					temp = ans[i][1];
					ans[i][1] = ans[i+1][1];
					ans[i+1][1] = temp;
				}




			for( int i=1 ; i<num_vertices  ; i++ )
				cout << ans[i][0] << " "<<ans[i][1] << endl;
			return;
		}
};

int main()
{
	int n_vert;
	cin >> n_vert;
	graph G(n_vert);

	G.insert();
	G.Prims();
	G.print();
	return 0;
}	
