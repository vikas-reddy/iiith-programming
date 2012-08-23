#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	public:
		int value;
		node *next;
};

class queue
{
	public:
		node *head;

		queue(){ head = NULL; }
		void enqueue(int val)
		{
			node *NewNode=NULL;
			NewNode = new node;
			NewNode->value = val;
			NewNode->next = NULL;

			NewNode->next = head;
			head = NewNode;
		}
		int dequeue()
		{
			if(!head)
			{
				cout << "Cannot dequeue from an empty queue\n" << endl;
				exit(1);
			}

			if(!head->next)
			{
				int return_value = head->value;
				delete head;
				head = NULL;
				return return_value;
			}
			node *ToDelNode;
			node *temp = head;
			for(  ;temp->next->next; temp=temp->next);

			ToDelNode = temp->next;
			int return_value = ToDelNode->value;
			temp->next = NULL;
			delete ToDelNode;
			return return_value;
		}
};

int main()
{
	queue Q;

	for(int i=0; i<10; i++)
	{
		int X = rand()%100;
		Q.enqueue(X);
		cout << X << " ";
	}
	cout << endl;

	for(int i=0; i<10; cout << Q.dequeue() << " ", i++);

	cout << Q.dequeue();
	cout << endl;
	return 0;
}
