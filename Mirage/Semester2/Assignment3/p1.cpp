#include <iostream>
using namespace std;

class tnode
{
	public:
		tnode *left;
		int data;
		tnode *right;
		tnode()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
};


class node
{
	public :
		tnode * data;
		node *next;
};
class stack
{
	private:
		node *top;

	public:

		stack()  {  top=NULL; }
		~stack()  {            }
		void push(tnode * num)
		{
			node *newnode;
			newnode = new node;
			newnode->data =  num;
			newnode->next = top;
			top=newnode;
			return;
		}
		tnode * gettop()
		{
			return top->data;
		}
		void pop()
		{
			node *t=top;
			top=top->next;
			delete t;
			return;
		}
		bool isempty()
		{
			if(top == NULL) 
				return true;
			return false;
		}
};

class AVLTree
{
	private:
		tnode *root;
	public:
		AVLTree()
		{
			root = NULL;
		}
		int  depth(tnode *a);
		int  balance_fact(tnode *a);
		void right_rotate(tnode *a);
		void left_rotate(tnode *a);
		void insert(int n);
		void balance(stack S);
		void traverse(tnode *a);
		void inorder(tnode *a);
		void preorder(tnode *a);
		void postorder(tnode *a);
		tnode * getroot()
		{
			return root;
		}
		bool search(int n,tnode *a);
		tnode *pointerof(int n);
		tnode *parentof(int n);
		void delnode(int n);
		bool isempty();

};
int AVLTree::depth(tnode *a)
	// Function to find depth of the tree from a given node "a"
{
	if( !a )// Returns 0 if a is NULL
		return 0;
	int hl=depth(a->left),hr=depth(a->right);
	if( hl>hr )
		return ( 1+hl );
	else return(1+hr);
}
int AVLTree::balance_fact(tnode *a)
	// Balance Factor
{
	if( !a )   return 0;
	return (depth(a->left)-depth(a->right));
}
void AVLTree::right_rotate(tnode *a)
	// Right rotation about node "a"
{
	tnode *temp=a->left;
	a->left = temp->right;
	temp->right = a;
	if( root == a )
		root = temp;
	else
	{
		tnode *P=parentof(a->data);
		if( a->data < P->data )
			P->left = temp;
		else
			P->right = temp;
	}
}
void AVLTree::left_rotate(tnode *a)
	// Left rotation about node "a"
{
	tnode *temp=a->right;
	a->right = temp->left;
	temp->left = a;
	if( root == a )
		root = temp;
	else
	{
		tnode *P=parentof(a->data);
		if( a->data < P->data )
			P->left = temp;
		else
			P->right = temp;
	}
}
void AVLTree::insert(int n)
	// Insert
{
	tnode *temp=NULL,*NN,*t=root;
	int d=0,e=0;
	stack S,S2;
	NN = new tnode;
	NN->data = n;
	if( !root ) 
	{
		root = NN;
		return;
	}
	S.push(root);
	while(1)
	{
		if( !t->left && !t->right )
		{
			if( n < t->data )     
				t->left = NN;
			else    
				t->right= NN;
			break;
		}
		if( n < t->data )
		{
			if( !t->left )   
			{   
				t->left = NN;  
				break;   
			}
			else 
			{
				t = t->left;
				S.push(t);
			}
		}
		else 
		{
			if( !t->right )  
			{	
				t->right = NN; 
				break;  
			}
			else 
			{
				t = t->right;
				S.push(t);
			}
		}
	}
	// Balance the tree
	balance(S);
}
void AVLTree::balance(stack S)
	// Balance the tree given the stack of pointers
{
	tnode *temp=NULL;
	for( temp=NULL; !S.isempty() ; temp = S.gettop(),S.pop() ) 
	{
		if( balance_fact(S.gettop()) <-1 )
		{
				
			if( balance_fact(temp) > 0 )
			{
				cout<<" Right at "
					<<temp->data<<" + Left at "
					<<S.gettop()->data<<" \n";
				right_rotate(temp);
				left_rotate( S.gettop() );
			}
			else 
			{
				cout<<" Left at "<< S.gettop()->data<<"\n";
				left_rotate( S.gettop() );
			}
		}
		if(  balance_fact(S.gettop())  >1 )
		{
			if( balance_fact(temp) < 0 )
			{
				cout<<" Left at "
					<<temp->data<<" + Right at "
					<<S.gettop()->data<<" \n";
				left_rotate( temp );
				right_rotate( S.gettop() );
			}
			else 
			{
				cout<<" Right at "<< S.gettop()->data<<"\n";
				right_rotate( S.gettop() );
			}
		}
	}	
	return;
}
void AVLTree::traverse(tnode *a)
	// Traverse of print
{
	cout<<" Inorder    : ";
	inorder(root);
	cout<<endl;
	cout<<" Preorder   : ";
	preorder(root);
	cout<<endl;
	cout<<" Postorder  : ";
	postorder(root);
	cout<<endl;
	return;
}
void AVLTree::inorder(tnode *a)
{
	if( a == NULL) 
		return;
	inorder(a->left);
	cout << a->data << " " ;
	inorder(a->right);
}
void AVLTree::preorder(tnode *a)
{
	if( a == NULL) 
		return;
	cout << a->data << " " ;
	preorder(a->left);
	preorder(a->right);
}
void AVLTree::postorder(tnode *a)
{
	if( a == NULL) 
		return;
	postorder(a->left);
	postorder(a->right);
	cout << a->data << " " ;
}
bool AVLTree::search(int n,tnode *a)
	// Search for a number n
{
	if( !a ) 
		return false;
	if( n == a->data ) 
		return true;
	if( n < a->data )
		return(search(n,a->left));
	else 
		return(search(n,a->right));
}
tnode *AVLTree::pointerof(int n)
	// returns the pointer pointing to the node containing "n"
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
tnode *AVLTree::parentof(int n)
	// Returns the parent of node containing number "n"
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
void AVLTree::delnode(int n)
	// Deleting a node 
{

	tnode *ptr=root;
	stack S;
	int r=root->data;
	S.push(root);
	if( r!=n )
	{
		// if n is not root->data
		while(1)
		{
			if ( !ptr ) break;
			if(ptr->data == n )
				break;
			else if( n > ptr->data )
			{
				ptr=ptr->right;
				S.push(ptr);
			}
			else if( n < ptr->data)
			{
				ptr=ptr->left;
				S.push(ptr);
			}
		}
	}
	tnode *temp=NULL,*t=NULL,*Prnt=NULL;
	if( r!= n )
		Prnt=parentof(n);
	if( !ptr->left )
	{
		temp = ptr;
		ptr = ptr->right;
		S.pop();
		if(ptr)  S.push(ptr);
		delete temp;
	}
	else if( !ptr->right )
	{
		temp = ptr;
		ptr = ptr->left;
		S.pop();
		if(ptr)  S.push(ptr);
		delete temp;
	}
	else if( !ptr->left->right )
	{
		temp = ptr;
		S.pop();
		ptr = ptr->left;
		ptr->right = temp->right;
		delete temp;
	}
	else
	{
		for(t=ptr->left ; t->right->right ; S.push(t),t=t->right );
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

	// Balancing
	balance(S);
	return;
}
bool AVLTree::isempty()
{
	if(root)
		return false;
	return true;
}

int main()
{
	AVLTree T;
	char ch;
	int n;
	while(1)
	{
		cin >> ch ; 
		switch(ch)
		{
			case'I':cin >> n;
				T.insert(n);
				break;
			case'T':T.traverse(T.getroot());
				break;
			case'S':cin >> n;
				cout << T.search(n,T.getroot())<<endl;
				break;
			case'D':cin >> n;
				T.delnode(n);
				break;
			case'R':cout<< T.getroot()->data<<endl;
				break;
			case'X':return 0;
		}
	}
}
