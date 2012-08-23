#include <iostream>
using namespace std;

class tnode
{
	public:
		int data;
		tnode *left;
		tnode *right;
		tnode()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
};

class BSTree
{
	public:
		tnode *root;
		int diameter;
		
		BSTree()
		{
			root = NULL;
			diameter = 0;
		}
		~BSTree()  { }
		void insert(int n)
		{
			tnode *NN,*t=root;
			NN = new tnode;
			NN->data = n;
			if( !root ) 
			{
				root = NN;
				return;
			}
			while(1)
			{
				if( !t->left && !t->right )
				{
					if( n < t->data )     t->left = NN;
					else                  t->right= NN;
					return;
				}
				if( n < t->data )
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
		void traverse(tnode *a)
		{
			if( a == NULL) 
				return;
			traverse(a->left);
			cout << a->data << " " ;
			traverse(a->right);
		}
		tnode * getroot()
		{
			return root;
		}
		bool search(int n,tnode *a)
		{
			if( a==NULL ) 
				return false;
			if( n == a->data ) 
				return true;
			if( n < a->data )
				return(search(n,a->left));
		}
		bool isempty()
		{
			if(root)
				return false;
			return true;
		}
		int height(tnode *a)
		{
			if(!a)
				return 0;
			int hl=height(a->left),hr=height(a->right);
			if( hl>hr )
				return ( 1 + hl );
			else 
				return ( 1 + hr );
		}
		void width(tnode *a)
		{
			if(!a)
				return;
			if( diameter < ( 1+height(a->left)+height(a->right) ) )
				diameter = 1+height(a->left)+height(a->right);
			width(a->left);
			width(a->right);
		}
			
};

int main()
{
	BSTree T;
	int n;
	cin >> n;
	while(n!=-1)
	{
		T.insert(n);
		cin >> n;
	}
	T.width(T.root);
	cout << T.diameter <<endl;
}
