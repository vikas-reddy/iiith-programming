#include <iostream> 
using namespace std; 

class Queue
{
	private:
		int arr[50];
		int front,back,size;
	public:
		Queue()  
		{
			front = back = 0 ;
			size = 0;
		}
		~Queue() {}
		void enqueue(int num)
		{
			if(!size) 
				arr[back]=num;
			else
			{
				back++;
				arr[back % 50]=num;
			}
			size++;
			return;
		}
		int dequeue()
		{
			//if(!size)  exit(0);
			int n=arr[front % 50];
			front ++ ;
			size--;
			return n;
		}
		void reverse()
		{
			int temp=0,f=front,l=back;
			while(f<l)
			{
				temp=arr[f];
				arr[f]=arr[l];
				arr[l]=temp;
				f++;
				l--;
			}
			return;
		}
		int qsize()
		{
			return size;
		}
		bool isempty()
		{
			if(size) return 0;
			return 1;
		}
		bool isfull()
		{
			if(size==50) 
				return 1;
			return 0;
		}
};

int main()
{
	Queue Q;
	char ch;
	int num;
	for( ch=getchar() ; ch!='\n' ;ch=getchar() ) 
	{
		switch(ch)
		{
			case'E':cin>>num;
				Q.enqueue(num);
				break;
			case'D':cout<<Q.dequeue()<<endl;
				break;
			case'R':Q.reverse();
				break;
			case' ':break;
			default:cout<<"Invalid Input";
				return 0;
		}
	}
	return 0;
}
				
			
		
		
