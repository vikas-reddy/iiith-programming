#include <iostream>
using namespace std;

class node
{
	public :
		int x;
		int y;
		node *next;
};
class stack
{
		node *top;
	public:
		stack()   {  top=NULL; }
		~stack()  {}
		void push(int X,int Y)
		{
			node *newnode;
			newnode = new node;
			newnode->x = X ;
			newnode->y = Y ;
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
		int getx()  
		{
			return top->x;
		}
		int gety()  
		{
			return top->y;
		}
		void Print()
		{
			node *t=top;
			for(  ;t;  )
			{
				cout<<'(';
				cout<<t->x<<',';
				cout<<t->y<<')'<<" ";
				t=t->next;
			}
			cout << endl;
			return;
		}
		bool isempty()
		{
			if(top==NULL) return true;
			else return false;
		}
};
stack reverse(stack st)
{
	stack temp;
	for( ;! st.isempty(); )
	{
		temp.push(st.getx(),st.gety());
		st.pop();
	}
	return temp;
}

int main()
{
	stack s;
	int m,n,row=0,col=0,state=0;
	cin >> m >> n;
	int a[m][n];
	for(int i=0 ; i<m ; i++)
		for(int j=0 ; j<n ;cin>>a[i][j],j++);
	row=0;
	col=0;
	s.push(row,col);
	a[0][0]=2;
	while(1)
	{
		if(s.isempty()) 
		{
			cout<<"Route does'nt exist\n";
			return 0;
		}
	//	cout << "ERROR\n";
		row=s.getx();
		col=s.gety();
		if(row >= m || col >=n) break;
		if(row==m-1 && col==n-1)  break;
		state=0;
		if(row+1<m && a[row+1][col]==1)
		{
			row=row+1;
			s.push(row,col);
			a[row][col]=2;
			state=1;
		}
		else
		{
			if(col+1<n && a[row][col+1]==1)
			{
				col=col+1;
				s.push(row,col);
				a[row][col]=2;
				state=1;
			}
			else
			{	
				if(row-1>=0 && a[row-1][col]==1)
				{
					row=row-1;
					s.push(row,col);
					a[row][col]=2;
					state=1;
				}
				else if(col-1>=0 && a[row][col-1]==1)
				{
					col=col-1;
					s.push(row,col);
					a[row][col]=2;
					state=1;
				}
			}
		}
		if(state==0) s.pop();
	}
	s=reverse(s);
	s.Print();
}
