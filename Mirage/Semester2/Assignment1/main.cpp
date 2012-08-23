#include<iostream>
using namespace std;

class node 
{
	private:
	node *next;
	node *prev;
	public:
	char str[100];
	node *getnext();
	node *getprev();
	void putnext(node *a);
};
node *node::getnext()
{
	return next;
}
node *node::getprev()
{
	return prev;
}
void node::putnext(node *a)
{
	next=a;
}
int main()
{
	int N=0,K=0,j=0;
	cin >> K >> N;
	char a[100];
	node *b[N],*ptr=NULL,*cur=NULL;
	for(int i=0 ; i<N ; i++)
	{
		b[i]=new node;
		cin >> a;
		for(j=0 ; a[j] != '\0' ; j++)
		b[i]->str[j] = a[j];
		b[i]->str[j] = '\0';
	}
	b[N-1]->putnext(b[0]);
	cur=b[0];
	for(int i=0 ; i<N-1 ; b[i]->putnext(b[i+1]),i++);
	if(K==1)
	{
		for(int i=0 ; i<N ;cout<<b[i]->str <<" ",i++);
		cout << endl;
		return 0;
	}
	for(int i=0 ; i<N ; i++)
	{
		for(j=1 ; j!=K-1 ; j++,cur = cur->getnext());
		ptr = cur->getnext();
		cur->putnext(ptr->getnext());
		cout << ptr->str << " ";
		delete ptr;
		cur = cur->getnext();
	}
	cout << endl;
	return 0;
}
	

