#include <iostream>
using namespace std;
//  int Stack
class stack
{
	private:
	class node
	{
		public :
			int data;
			node *next;
	};
	node *top;
	public:
		stack()   { top=NULL; }
		~stack()  {           }
		void push(int num)
		{
			node *newnode;
			newnode = new node;
			newnode->data =  num;
			newnode->next = top;
			top=newnode;
			return;
		}
		int gettop()
		{
			if (top)
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
			if(!top) 
			       	return true;
			return false;
		}
		void evaluate(char ch)
		{
			int a=top->data,b=top->next->data;
			node *t=top;
			top=top->next;
			delete t;
			switch(ch)
			{
				case'+':top->data=a+b; break;
				case'-':top->data=b-a; break;
				case'*':top->data=a*b; break;
				case'/':top->data=b/a; break;
			}
			return;
		}
};
// char Stack
class charstack
{
	class charnode
	{
		public :
			char ch;
			charnode *next;
	};
	charnode *top;
	public:
	charstack()  {top=NULL;}
	~charstack() {         }
	void push(char c)
	{
		charnode *newcharnode;
		newcharnode = new charnode;
		newcharnode->ch =  c;
		newcharnode->next = top;
		top=newcharnode;
		return;
	}
	void pop()
	{
		charnode *t=top;
		top=top->next;
		delete t;
		return;
	}
	int gettop()
	{
		if(top)
			return top->ch;
	}
	bool isempty()
	{
		if(!top) 
			return true;
		return false;
	}
};
int prc(char ch)
{
	switch(ch)
	{ 
		case'+':return 1;
		case'-':return 2;
		case'*':return 3;
		case'/':return 4;
		default:return 0;
	}
}
int main()
{
	charstack S;
	stack ANS;
	int N=0;
	char ch;
	for( ch=getchar() ; ch!='\n' ;   )
	{
		if(isdigit(ch)) 
		{
			for(N=0;isdigit(ch);)
			{
				N=N*10+int(ch-'0');
				ch=getchar();
			}
			ANS.push(N);
		}
		else 
		{
			if(ch!=' ')	
			switch(ch)
			{
				case'(': S.push(char(ch));
					 break;
				case')': if(S.isempty()) 
						 return 0;
					 for(;1;)
					 {
						 ANS.evaluate(char(S.gettop()));
						 S.pop();
						 if(S.isempty()) return 0;
						 if(S.gettop()=='(') { S.pop();break; }
					 }
					 break;
				default: if(S.isempty()) S.push(ch);
					 else
					    if( prc(ch) > prc(S.gettop()) )
							 S.push(ch);
					    else
					    {
						 while( prc(ch) <= prc(S.gettop()))
						 {
						 	 ANS.evaluate(char(S.gettop()));
							 S.pop();
						 }
						 S.push(ch);
					   }
					 break;
			}
			ch=getchar();
		}
	}
	for(  ;!S.isempty(); )
	{	
		ANS.evaluate(S.gettop()) ;
		S.pop();
	}
	cout<<ANS.gettop();
	cout<< endl;
	return 0;
}
