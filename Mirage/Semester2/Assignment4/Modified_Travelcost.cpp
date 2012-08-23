#include<iostream>
using namespace std;

class graph
{
	private:
		int **mat;
		int num_vertices;
		int *cities;
		int num_cities;
		int *dist;
	public:
		graph(int num_vertices,int num_cities)
		{
			this->mat = new int*[num_vertices];
			for(int i=0 ; i<num_vertices ; i++ )
				this->mat[i] = new int[num_vertices];
			for(int i=0 ; i<num_cities ; i++ )
				this->cities = new int[num_cities];
			
			this->dist = new int[num_vertices];
			this->num_vertices = num_vertices;
			this->num_cities   = num_cities;
			return;
		}
		void insert()
		{
			for( int i=0 ; i<num_cities ; cin>>cities[i] , i++ );
			for( int i=0 ; i<num_vertices ; i++ )
				for(int j=0 ; j<num_vertices ; cin>>mat[i][j] , j++ );
			return;
		}
		int *djikstra(int node)
		{
			bool known[num_vertices];
			int   prev[num_vertices];
			int min,index,value;
			
			for( int i=0 ; i<num_vertices ; i++ )
			{
				known[i] = false;
				dist[i]  = 1000;
				prev[i]  = -1 ;
			}
			dist[node] = 0;
			prev[node] = -1;

			for( int count=0 ; count<num_vertices ; count++ )
			{
				// Searching the minimum element
				min = 1000;
				index = 0;
				for( int i=0 ; i<num_vertices ; i++ )
				{
					if( !known[i] )
						if( dist[i]!=1000 )
							if( min > dist[i] )
							{
								min = dist[i];
								index = i;
							}
				}
				known[index] = true;
				value = min;
				// updating the dist[] and prev[] arrays
				for( int i=0 ; i<num_vertices  ; i++ )
				{
					if( !known[i] && mat[index][i] )
						if( dist[index]+mat[index][i] < dist[i] )
						{
							dist[i] = dist[index]+mat[index][i];
							prev[i] = index;
						}
				}

			}
			//for( int i=0 ; i<num_vertices ; cout<<dist[i]<<" " , i++ );
			//cout << endl;
			return dist;

		}
		int least_cost(int homenode)
		{
			bool flag[num_vertices];
			int count=0,number=0,index=0,min=0;
			int ptr;
			
			for( int i=0 ; i<num_vertices ; flag[i]=true , i++ );
			for( int i=0 ; i<num_cities ; i++ )
			{
				flag[ cities[i] ] = false;
			}

			ptr = homenode;
			for(int j=0 ; j<num_cities ; j++ )
			{
				dist = djikstra(ptr);
				flag[ptr] = true;
				for( int i=0,min=1000  ; i<num_vertices ; i++ )
				{
					if( !flag[i] )
						if( min > dist[i] )
						{
							min = dist[i];
							ptr = i;
						}
				}
				count = count+dist[ptr];
			}
			dist = djikstra(ptr);
			min = dist[homenode];
			
			count = count+min;
			return count;
			
		}
		int answer()
		{
			int min=1000,temp;
			for( int i=0 ; i<num_cities ; i++ )
			{
				temp = least_cost(cities[i]);
				if( min>temp )
					min = temp;
			}
			return min;
		}
		
};

int main()
{
	int n_cit,n_vert;
	cin >> n_vert;
	cin >> n_cit ;
	graph G(n_vert,n_cit);
	G.insert();
	cout << G.answer() << endl;
	return 0;
}
