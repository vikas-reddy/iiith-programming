#include <iostream>
using namespace std;

class BTree
{
	private:
		int    arr[1024];
		bool valid[1024];
	public:
		BTree()
		{
			for(int i=0; i<1024 ;
				  arr[i]=0,valid[i]=false,i++);
		}
		~BTree() {}
		int leftchild (int x)     {  return (2*x);   }
		int rightchild(int x)	  {  return (2*x+1); }
		void insert(int num)
		{
			if(  ! valid[1]  )
			{
				arr[1] = num;
				valid[1] = true;
				return;
			}
			int i=0;
			for( i=1 ; valid[i] ;   )
			{
				if( num < arr[i] )
					i = leftchild(i);
				else
					i = rightchild(i);
			}
			arr[i] = num;
			valid[i] = true;
			return;
		}
		bool search(int num)
		{
			for( int i=1 ; valid[i] ;   )
			{
				if ( num == arr[i] )
					return true;
				if( num < arr[i] )
					i = leftchild(i);
				else 
					i = rightchild(i);
			}
			return false;
		}
		void traverse()
		{
			if( !valid[1] )
				return;
			preorder( 1 );	
			inorder( 1);	
			postorder( 1);	
		}
		void preorder( int x )
		{
			if( !valid[x] )
				return;
			cout << arr[x] << " ";
			preorder( 2*x );
			preorder( 2*x + 1 );
		}
		void inorder( int x )
		{
			if( !valid[x] )
				return;
			inorder( 2*x );
			cout << arr[x] << " ";
			inorder( 2*x + 1 );
		}
		void postorder( int x )
		{
			if( !valid[x] )
				return;
			postorder( 2*x );
			postorder( 2*x + 1 );
			cout << arr[x] << " ";
		}
		void remove(int num)
		{
			int i=0,j=0;
			for( i=1 ; valid[i] ;   )
			{
				if ( num == arr[i] )
					break;
				if( num < arr[i] )
					i = leftchild(i);
				else 
					i = rightchild(i);
			}
			while(  valid[ leftchild(i) ]  || valid[ rightchild(i) ]  )
			{
				if( valid[ rightchild(i) ] )
					for( j = rightchild(i) ; valid[leftchild (j)] ; j=leftchild (j) );
				else 
					for( j = leftchild (i) ; valid[rightchild(i)] ; j=rightchild(j) );
				arr[i] = arr[j];
				i=j;
			}
			valid[i] = false;
			return;
		}
};		
				
int  main()
{
	BTree T;
	int n;
	char ch;
	for(  cin>>ch ; ch!='E' ; cin>>ch )
	{
		switch(ch)
		{
			case'I':cin >> n;
				if( T.search(n) )
				{
					cout << "F ";
					break;
				}
				T.insert(n);
				cout << "S ";
				break;
			case'S':cin>>n;
				if( T.search(n) )
					cout<< "S ";
				else
					cout<< "F ";
				break;
			case'D':cin >> n;
				if( !T.search(n) )
				{
					cout << "F ";
					break;
				}
				T.remove(n);
				cout << "S ";
				break;
			default:break;
		}
	}
	T.traverse();
	cout << endl;
	return 0;
}
