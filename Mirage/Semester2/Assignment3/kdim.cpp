#include <iostream>
#include <stdlib.h>
using namespace std;


class tnode
{
	public:
		int *data;
		tnode *left;
		tnode *right;
		
		tnode(int dim)
		{
			for( int i=0 ; i<dim ; i++ )
			{
				data = new int[dim];
			}
			left = NULL;
			right = NULL;
		}
};


class BSTree
{
	public:
		tnode *root;
		int dim;
		BSTree(int k)
		{
			dim = k;
			root = NULL;
		}
		~BSTree()  { }
		void insert(int n[])
		{
			tnode *NN,*t=root;
			NN = new tnode(dim);
			for(int v=0 ; v < dim ; NN->data[v] = n[v] , v++);
			NN->left = NULL;
			NN->right = NULL;
			if( !root ) 
			{
				root = NN;
				return;
			}
			while(1)
			{
				if( !t->left && !t->right)
				{
					if( n[0] < t->data[0] )     t->left = NN;
					else                        t->right= NN;
					return;
				}
				if( n[0] < t->data[0] )
				{
					if( t->left==NULL )   {   t->left = NN;  return;   }
					else t = t->left;
				}
				else 
				{
					if( t->right==NULL )  {	  t->right = NN; return;   }
					else t = t->right;
				}
			}

		}
		tnode * getroot()
		{
			return root;
		}
		bool search(int n[],tnode *a)
		{
			
			if( a==NULL ) 
				return false;
			
			
			int state=0;
			
			for( int v=0 ; v < dim ; v++ )
			{
				if( n[v] == a->data[v] )
					state = 1;
				else 
				{	state = 0;
					break;
				}
			}
			if( state == 1)
				return true;
			
			
			if( n[0] < a->data[0] )
				return(search(n,a->left));
			else
				return(search(n,a->right));
		}
};

int main()
{
	int k;
	cin >> k;
	char ch;
	int n[k];
	BSTree T(k);
	while(1)
	{
		cin >> ch;
		switch(ch)
		{
			case'i':
				for(int v=0 ; v<k ;  cin>>n[v] , v++ );
				if(  T.search(n,T.getroot()) )
					cout << "No\n" ;
				else
				{
					T.insert(n);
					cout << "Yes\n";
				}
				break;
			case's':
				for(int v=0 ; v<k ;  cin>>n[v] , v++ );
				if( !T.search(n,T.getroot()) )
					cout << "No\n";
				else
					cout<<  "Yes\n";
				break;
			case'E':
				return 0;
		}

	}
}
