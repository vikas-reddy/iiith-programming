#include <iostream>
using namespace std;

class graph
{
	private:
		int **mat;
		int num_vertices;
		bool *known;
	public:
		graph(int a)
		{
			mat = new int*[a];
			for(int i=0 ; i<a ; i++ )
				mat[i] = new int[a];
			num_vertices = a;
			known = new bool[a];
			for( int i=0 ; i<num_vertices ; known[i]=false , i++ );

			return;
		}
		void insert()
		{
			for(int i=0 ; i<num_vertices ; i++ )
				for( int j=0 ; j<num_vertices ; j++)
					cin >> mat[i][j];
			return;
		}
		void bfs(int node,int parent)
		{
			for( int i=0 ; i<num_vertices ; i++ )
			{
				if( mat[node][i] && i!=parent )
				{
					if( known[i] )
					{
						cout << "NO\n";
						exit(0);
					}
					else 
					{
						known[i] = true;
						bfs(i,node);
					}
				}
			}
		}
};

int main()
{
	int num_vertices;
	cin>>num_vertices;
	graph G(num_vertices);

	G.insert();
	G.bfs(0,-1);
	cout << "YES\n";
	return 0;
}
