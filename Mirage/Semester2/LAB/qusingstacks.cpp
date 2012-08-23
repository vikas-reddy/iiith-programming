#include <iostream>
using namespace std;

class node
{
	public :
		int data;
		node *next;
};
class stack
{
		node *top;
	public:
		stack()   {  top=NULL; }
		~stack()  {}
		void push(int num)
		{
			node *newnode;
			newnode = new node;
			newnode->data =  num;
			newnode->next = top;
			top=newnode;
			return;
		}
		int pop()
		{
			node *t=top;
			int value=t->data;
			top=top->next;
			delete t;
			return value;
		}
		bool isempty()
		{
			if(top == NULL) 
			       	return true;
			return false;
		}
		void Print()
		{
			node *t=top;
			for(  ;t;  cout<<t->data<<" " , t=t->next);
			cout << endl;
			return;
		}
};

class Que
{
	private:
		stack a,temp;
	public:
		Que()  {}
		~Que() {}
		void NQ(int n)
		{
			a.push(n);
		}
		int DQ()
		{
			for( ;  a.isempty()!=true    ; temp.push(a.pop()));
			int y=temp.pop();
			for( ;  temp.isempty()!=true ; a.push(temp.pop()));
			return y;
		}
		void print()
		{
			a.Print();
		}
};	

int main()
{
	Que one;
	int w=0;
	char ch;
	while(1)
	{
		cin>>ch;
		if(ch=='n')
		{
			cin >> w;
			one.NQ(w);
		}
		if(ch=='d')
		{
			cout<<one.DQ()<<endl;
		}
		if(ch=='p') one.print();
		if(ch=='x')
		{
			break;
		}
		
	}
	return 0;
}
