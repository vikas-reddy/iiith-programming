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
	private:
		tnode *root;
	public:
		BSTree()
		{
			root = NULL;
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
		tnode * getroot()
		{
			return root;
		}
};
void inorder(tnode *a,tnode *b)
{
	if( a == NULL || b==NULL)
		return;
	inorder(a->left,b->left);
	if( a->data != b->data )
	{
		cout << "No\n";
		exit(0);
	}
	inorder(a->right,b->right);
}
void preorder(tnode *a,tnode *b)
{
	if( a == NULL || b==NULL)
		return;
	if( a->data != b->data )
	{
		cout << "No\n";
		exit(0);
	}
	inorder(a->left,b->left);
	inorder(a->right,b->right);
}

int main()
{
	int num;
	BSTree T1,T2;
	for( cin>>num ; num!=(-1) ; T1.insert(num) , cin>>num );
	for( cin>>num ; num!=(-1) ; T2.insert(num) , cin>>num );
	inorder(T1.getroot(),T2.getroot());
	preorder(T1.getroot(),T2.getroot());
	cout << "Yes\n";
}

