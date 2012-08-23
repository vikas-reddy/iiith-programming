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
	private:
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
int prc(char ch)
{
	switch(ch)
	{ 
		case'+':return 1;
		case'-':return 2;
		case'*':return 3;
		case'/':return 4;
		case'(':return -1;
		case')':return -2;
		default:return 0;
	}
}

int main()
{
	stack OPER;
	stack S;
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
			S.push(N);
		}
		else 
		{
			if(ch!=' ')	
			switch(ch)
			{
				case'(': OPER.push(int(ch));
					 break;
				case')': if(OPER.isempty()) 
						 return 0;
					 for(;1;)
					 {
						 S.evaluate(char(OPER.gettop()));
						 OPER.pop();
						 if(OPER.isempty()) return 0;
						 if(OPER.gettop()=='(') { OPER.pop();break; }
					 }
					 break;
				default: if(OPER.isempty()) OPER.push(ch);
					 else
					    if( prc(ch) > prc(char(OPER.gettop())) )
							 OPER.push(ch);
					    else
					    {
						 while( prc(ch) <= prc(char(OPER.gettop())))
						 {
						 	 S.evaluate(char(OPER.gettop()));
							 OPER.pop();
						 }
						 OPER.push(int(ch));
					   }
					 break;
			}
			ch=getchar();
		}
	}
	for(  ;!OPER.isempty(); )
	{	
		S.evaluate(char(OPER.gettop())) ;
		OPER.pop();
	}
	cout<<S.gettop();
	cout<< endl;
	return 0;
}
