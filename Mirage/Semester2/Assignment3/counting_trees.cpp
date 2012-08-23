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
					
};

int main()
{
	BSTree T;
	char ch;
	int n;
	while(1)
	{
		cin >> ch ; 
		switch(ch)
		{
			case'i':cin >> n;
				T.insert(n);
				break;
			case't':T.traverse(T.getroot()); 
				cout << endl;
				break;
			case's':cin >> n; 
				cout << T.search(n,T.getroot())<<endl;
				break;
			case'd':cin >> n;
				T.delnode(n);
				break;
			case'f':cin>>n;
				cout << T.parentof(n)->data<<endl;
				break;
			case 'r':cout<< T.getroot()->data<<endl;
				 break;
			case'x':return 0;
		}
	}
}
