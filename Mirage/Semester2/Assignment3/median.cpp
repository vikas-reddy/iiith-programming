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
		int quantity;
		BSTree()
		{
			root = NULL;
			quantity = 0 ;
		}
		~BSTree()  { }
		void insert(int n)
		{
			tnode *NN,*t=root;
			NN = new tnode;
			NN->data = n;
			quantity++;
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
		void del_largest()
		{
			if( !root )   return;
			tnode *temp,*t;
			quantity--;
			if( !root->right )
			{
				temp = root;
				root=root->left;
				delete temp;
				return;
			}
			for( t=root ; t->right->right ; t=t->right);
			temp = t->right;
			t->right = t->right->left;
			delete temp;
			return;
		}
		void del_smallest()
		{
			if( !root )   return;
			tnode *temp,*t;
			quantity--;
			if( !root->left )
			{
				temp = root;
				root=root->right;
				delete temp;
				return;
			}
			for( t=root ; t->left->left ; t=t->left);
			temp = t->left;
			t->left = t->left->right;
			delete temp;
			return;
		}
		void median()
		{
			while( quantity > 2 )
			{
				del_smallest();
				del_largest();
			}
			if( quantity == 1 )
				cout<<root->data<<endl;
			if(quantity == 2)
			{
				if( root->right )
					cout<<root->data<<endl;
				else
					cout<<root->left<<endl;
			}
		}

					
};

int main()
{
	int num;
	BSTree T;
	cin >> num;
	while( num != -1 )
	{
		T.insert(num);
		cin >> num;
	}
	T.median();
}
