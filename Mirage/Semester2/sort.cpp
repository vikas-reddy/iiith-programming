#include <iostream>
using namespace std;
 
class node
{
	private:
		int data;
		node *next;
	public:
		node() {data = 0;}
		~node(){}
		int getdata()         { return data;  }
		node *getnext()       { return next;  }
		void putnext(node *y) { next = y;     }
		void putdata(int num) { data = num;   }
		void print()          { cout << data; }
};

node *Insert(node *start,int num)
{
	node *nn,*t=start;
	nn = new node;
	nn->putdata(num);
	nn->putnext(NULL);
	if(t==NULL)  return nn;
	for(  ;t->getnext(); t=t->getnext());
	t->putnext(nn);
	return start;
}
	
void Print(node *start)
{
	node *temp=start;
	for(  ;temp; temp=temp->getnext() )
	{
		temp->print();
		cout << " " ;
	}
	cout << endl;
	return;
}
node *Sort(node *start)
{
	node *temp=start;
	
	return temp;
}

int main()
{
	node *start=NULL;
	for( int i=0 ; i<10 ; i++)
		start = Insert(start,rand()%100);
	start = Sort(start);
	Print(start);
}
	
