#include <iostream>
using namespace std;

class node 
{
	public:
		int data;
		node *next;
};

class queue
{
	private:
		node *front;
		node *back;
	public:
		queue()	{   front = back =  NULL;  }
		~queue(){                          }
		void enqueue(int n)	
		{
			node *NewNode;
			NewNode = new node;
			NewNode->next = NULL;
			NewNode->data = n;
			if( back == NULL)
			{
				back = NewNode;
				front = NewNode;
			}
			back->next = NewNode;
			back = NewNode;
			back->next = NULL;
			return;
		}
		int dequeue()
		{
			node *t=front;
			int num=front->data;
			front = front->next;
			delete t;
			return num;
		}
		/*void Print()
		{
			for(node *t=front ; t != back->next ;
				cout<<t->data<<" " , t=t->next);
			cout << endl;
			return;
		}*/
};

int main()
{
	queue Q;
	for(int i=0 ; i<10 ; Q.enqueue(i),i++);
	//Q.Print();
	for(int i=0 ; i<10 ; cout<<Q.dequeue()<<" " , i++);
	cout << endl;
}
