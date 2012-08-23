#include <iostream>
using namespace std;

class node
{
	public :
		char ch;
		node *next;
};
class stack
{
	node *top;
	public:

	stack()  {  top=NULL;  }
	~stack(){}
	void push(char c)
	{
		node *newnode;
		newnode = new node;
		newnode->ch =  c;
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
	int gettop()
	{
		if(top != NULL)
			return top->ch;
	}
	bool isempty()
	{
		if(top == NULL) 
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
	stack S;
	int N=0;
	char ch;
	for( ch=getchar() ; ch!='\n' ;    )
	{
		if(isdigit(ch)) 
		{
			for(N=0;isdigit(ch);)
			{
				N=N*10+int(ch-'0');
				ch=getchar();
			}
			cout << N <<" ";
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
					 while(1)
					 {
						 cout<<char(S.gettop())<<" ";
						 S.pop();
						 if(S.gettop()=='(') 
						 { 
							 S.pop();
							 break; 
						 }
						 if(S.isempty()) 
						 {
							 cout << "ERROR\n";
							 return 0;
						 }
					 }
					 break;
				
				default: if(S.isempty()) 
						 S.push(ch);
					 else
					 {
						 if( prc(ch) > prc(S.gettop()) )
							 S.push(ch);
						 else
						 {
							 while( prc(ch) <= prc(S.gettop()))
							 {
								 cout<<char(S.gettop())<<" ";
								 S.pop();
								 //if(S.isempty()) return 0;
							 }
							 S.push(ch);
						 }
					 }
					 break;
			}
			ch=getchar();
		}
	}
	for(    ;!S.isempty();  cout<<char(S.gettop())<<" " , S.pop() );
	cout<< endl;
	return 0;
}
