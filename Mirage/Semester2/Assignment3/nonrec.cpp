#include <iostream>
using namespace std;

class tnode
{
	public:
		int data;
		bool flag;
		tnode *left;
		tnode *right;
		tnode()
		{
			data = 0;
			flag = false;
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
		void preorder(tnode *a)
		{
			if( !a ) 
				return;
			while(1)
			{
				if( !a->flag )
				{
					cout << a->data << " ";
					a->flag = true;
				}
				if     ( a->left  &&   !a->left->flag   )
					a = a->left;
				else if( a->right &&   !a->right->flag  )
						a = a->right;
				else if( a != root )
					a = parentof(a->data);
				else
					break;
			}
			return ;
		}
		/*void rec_preorder(tnode *a)
		{
			if( !a ) 
				return;
			cout << a->data << " " ;
			rec_preorder(a->left);
			rec_preorder(a->right);
		}*/
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
		tnode *parentof(int n)
		{
			if(root->data == n )
			{
				cout<<" Parent does not exist for root\n";
				exit(0);
			}
			tnode *temp=root;
			while(1)
			{
				if( !temp->left && !temp->right )  return NULL;
				if( n < temp->data )
				{
					if( temp->left )
					{
						if(temp->left->data == n)  return temp;
						else  temp=temp->left;
					}
					else 
						return NULL;
				}
				else if( n > temp->data)
				{
					if( temp->right )
					{
						if(temp->right->data == n) return temp;
						else  temp=temp->right;
					}
					else 
						return NULL;
				}
			}
		}
					
};

int main()
{
	BSTree T;
	int n;
	cin >> n;
	while ( n != -1 )
	{
		T.insert(n);
		cin >> n;
	}
	T.preorder(T.getroot());
		cout << endl;
	return 0;
}
