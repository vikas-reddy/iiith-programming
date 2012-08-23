#include <iostream>
using namespace std;

int power(int a, int b)
{
	int ans=1;
	for( int i=0 ; i<b ; ans=ans*a , i++);
	return ans;
}
	
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
		void traverse(tnode *a)
			// Traverse or print
		{
			preorder(root);
			cout<<endl;
			inorder(root);
			cout<<endl;
			postorder(root);
			cout<<endl;
			return;
		}
		void inorder(tnode *a)
		{
			if( a == NULL) 
				return;
			inorder(a->left);
			cout << a->data << " " ;
			inorder(a->right);
		}
		void preorder(tnode *a)
		{
			if( a == NULL) 
				return;
			cout << a->data << " " ;
			preorder(a->left);
			preorder(a->right);
		}
		void postorder(tnode *a)
		{
			if( a == NULL) 
				return;
			postorder(a->left);
			postorder(a->right);
			cout << a->data << " " ;
		}
		void putroot(tnode *x)
		{
			root = x;
		}
		tnode *getroot()
		{
			return root;
		}
};

int main()
{
	int h,y;
	cin >> h;
	
	if( h == 0 )
		return 0;
	
	BSTree T;
	tnode *node[ power(2,h) - 1 ]   ;
	int    num [ power(2,h) - 1 ];
	
	
	for( int i=0 ; i<( power(2,h)-1 ) ; cin>>num[i] , i++ );
	
	node[0] = new tnode;
	node[0]->data = num[0];
	node[0]->left = NULL;
	node[0]->right = NULL;


	for( int i=0 ; i<(h-1) ; i++ ) 
		for( int x=( power(2,i)-1 ),y=(power(2,i+1)-1) ; x < ( power(2,i+1)-1 ) ; x++ ,y=y+2 )
		{
			if( num[y]==(-1) )
			{
				if(num[x]!=-1)   node[x]->left = NULL;
			}
			else
			{
				node[y] = new tnode;
				node[y]->data =  num[y];
				node[y]->left = NULL;
				node[y]->right = NULL;
			
				node[x]->left = node[y];
			}
			if( num[y+1]==(-1) )
			{	
				if(num[x]!=-1)   node[x]->right = NULL;
			}
			else
			{
				node[y+1] = new tnode;
				node[y+1]->data =  num[y+1];
				node[y+1]->left = NULL;
				node[y+1]->right = NULL;
				  node[x]->right = node[y+1];
			}
		}
	T.putroot(node[0]);
	T.traverse(T.getroot());
	return 0 ;
}



