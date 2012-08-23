#include <iostream>
using namespace std;

class MinHeap
{
	private:
		int *arr;
		bool *valid;
		int position;
	public:
		MinHeap(int x)
		{
			arr   = new int [x];
			valid = new bool[x];
			position = 1;
			for ( int i=0 ; i < x ; valid[x] = false,i++ );
		}
		int leftchild (int x)   {  return ( 2*x );	}
		int rightchild(int x)   {  return ( 2*x + 1 );	}
		int parent    (int x)   {  return ( x/2 );	}
		void insert(int num)
		{
			int i,temp;
			arr[position] = num;
			valid[position] = true ;
			for( i=position  ; parent(i)  &&  num < arr[parent(i)]  ;     )
			{
		//		cout << arr[i] << " ---> " << arr[parent(i)]<<endl;
			/*	temp = arr[i];
				arr[i] = arr[parent(i)];
				arr[parent(i)] = temp;
			*/	
				arr[i] = arr[ parent(i) ];
				i = parent(i);
			}
			arr[i] = num;
			position ++;
			return;
		}
		int remove()
		{
			if( position == 1 )
				return 0 ;
			position -- ;
			valid[position] = false ;
			int temp,small = arr[1];
			arr[1] = arr[ position ];
			for( int i=1 ; valid[i] ;   )
			{
				if(  arr[i]<arr[leftchild(i)]  && 
						arr[i]<arr[rightchild(i)]  )
					break;
				else if( valid[leftchild(i)] && arr[leftchild(i)] < arr[rightchild(i)] )
				{
				//	cout << arr[i] << " ---> "<< arr[leftchild(i)] << endl;
					temp = arr[leftchild(i)];
					arr[leftchild(i)] = arr[i];
					arr[i] = temp;
					
					i = leftchild(i);
				}
				else if(valid[rightchild(i)] &&  arr[rightchild(i)] < arr[ leftchild(i) ] )
				{
				//	cout << arr[i] << " ---> "<< arr[rightchild(i)] << endl;
					temp = arr[i];
					arr[i] = arr[rightchild(i)];
					arr[rightchild(i)] = temp;
					
					i = rightchild(i);
				}
				else break;
			}
			return small;
		}
		void inorder(int x)
		{
			if( !valid[x] )
				return;
			inorder( leftchild(x) );
			cout << arr[x] << " ";
			inorder( rightchild(x) );
			return;
		}
		void preorder(int x)
		{
			if ( !valid[x] )
				return;
			cout << arr[x] << " " ;
			preorder( leftchild(x) );
			preorder( rightchild(x) );
			return;
		}
		bool isempty()
		{
			if( position == 1 )
				return true;
			else
				return false;
		}
};

int main()
{
	char ch;
	int n;
	MinHeap H(64);
	for( cin >> ch ; ch!='X' ; cin >> ch  )
	{
		switch(ch)
		{
			case'I':
				cin >> n;
				while( n != -1)
				{
					H.insert(n);
					cin >> n ;
				}
				break;
			case'R':
				if (H.isempty())
					cout<<"No elements in the heap\n";
				else
					cout <<"Smallest Element is "<<H.remove() << endl;
				break;
			case'P':
				H.inorder(1);
				cout <<endl;
				H.preorder(1);
				cout <<endl;
				break;
			default:break;
		}
	}
	return 0;
}
	
