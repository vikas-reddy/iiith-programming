#include <iostream>
using namespace std;

class node
{
	public :
		float data;
		node *next;
};
class stack
{
	node *top;
	public:

	stack()  {top=NULL;}
	void push(float num)
	{
		node *newnode;
		newnode = new node;
		newnode->data =  num;
		newnode->next = top;
		top=newnode;
		return;
	}
	void pop()
	{
		node *t=top;
		top=top->next;
		delete t;
		return;
	}
	float gettop()
	{
		if(top != NULL)
			return top->data;
	}
	bool isempty()
	{
		if(top == NULL) 
			return true;
		return false;
	}
	void print()
	{
		for(node *t=top; t!=NULL ; cout<<t->data<<" ",t=t->next);
		cout << endl;
		return;
	}
};
int main()
{
	stack s;
	char str[50],ch;
	float a=0,b=0;
	cin.getline(str,50);
	for(int i=0 ; str[i]!='\0' ;i++)
	{
		if( isdigit(str[i]) )
				s.push(int(str[i]-'0'));
		else if(str[i]!=' ')
		{
			a=s.gettop();
			s.pop();
			b=s.gettop();
			s.pop();
			switch(str[i])
			{
				case '+':  s.push(a+b);   break;
				case '-':  s.push(b-a);   break;
				case '*':  s.push(a*b);   break;
				case '/':  s.push(b/a);	  break;
			}
		}
	}
	cout << "Answer = " << s.gettop() << endl;
	return 0;
}
