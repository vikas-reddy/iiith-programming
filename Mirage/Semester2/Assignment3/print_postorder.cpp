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
		tnode *pointerof(int n)
		{
			tnode *a=root;
			while(1)
			{
				if ( !a ) break;
				if(a->data == n )
					return a;
				else if( n > a->data )
					a=a->right;
				else if( n < a->data)
					a=a->left;
			}
			cout<<"The number "<< n<<" does not exist in the tree\n";
			exit(0);
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
		void delnode(int n)
		{
			tnode *ptr=pointerof(n),*temp=NULL,*t=NULL,*Prnt=NULL;
			int r=root->data;
			if( r!= n )
				Prnt=parentof(n);
			if( !ptr->left )
			{
				temp = ptr;
				ptr = ptr->right;
				delete temp;
			}
			else if( !ptr->right )
			{
				temp = ptr;
				ptr = ptr->left;
				delete temp;
			}
			else if( !ptr->left->right )
			{
				temp = ptr;
				ptr = ptr->left;
				ptr->right = temp->right;
				delete temp;
			}
			else
			{
				for(t=ptr->left ; t->right->right ; t=t->right );
				temp = t->right;
				ptr->data = t->right->data;
				t->right = t->right->left;
				delete temp;
			}
			if( n == r )
				root = ptr;
			else if( n < Prnt->data )
				Prnt->left = ptr;
			else if( n > Prnt->data )
				Prnt->right = ptr;
			return;
		}
		bool isempty()
		{
			if(root)
				return false;
			return true;
		}
		void postorder(tnode *a)
		{
			if( a == NULL) 
				return;
			postorder(a->left);
			postorder(a->right);
			cout << a->data << " " ;
		}

};

int main()
{
	BSTree T;
	int n;
	cin >> n;
	int arr[(2*n)];
	for( int i=0 ; i<(2*n) ; cin>>arr[i], i++ );
	for( int i=n ; i<(2*n) ; T.insert(arr[i]), i++);
	T.postorder(T.getroot());
	cout<<endl;
	return 0;
}
