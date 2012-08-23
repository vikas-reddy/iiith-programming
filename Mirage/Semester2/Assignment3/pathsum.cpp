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
		int sum;
		int count;
		int max;
		
		BSTree()
		{
			root = NULL;
			sum = 0 ;
			count = 0;
		}
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
		void pathsum(tnode *a)
		{
			if( a==NULL )
				return;
			sum = sum + a->data;
			if( sum > max )
			{
				sum = sum - a->data;
				return;
			}
			if( !a->left && !a->right )
			{
			//	cout << sum << endl;
				count ++;
			}
			pathsum(a->left);
			pathsum(a->right);
			sum = sum - a->data;
			return;
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
	cin >> T.max;
	T.pathsum(T.root);
	cout << T.count << endl;
}
