#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class out
{
	public:
		int ch;
		out *next;
};
void print(out *start)
{
	out *t=start;
	for( ;t; )
	{
		if(t->ch == 39) 
		{
			cout << endl;
			t=t->next;
		}
		if(t)
		{
			cout << t->ch ;
			cout << " " ;
			t=t->next;
		}
	}
}
Node *reverse(Node *start)
{
	Node *prev,*temp,*cur;
	prev=NULL;
	cur=start;
	while(cur!=NULL)
	{
		temp=cur->next;
		cur->next=prev;
		prev=cur;
		cur=temp;
	}
	return prev;
}
Node *clear(Node *start)
{
	Node *temp;
	for(;start;)
	{
		temp=start->next;
		delete start;
		start=temp;
	}
	return start;

}
int find(Node *start,int x)
{
	Node *t=start;
	int ind=0;
	for( ; t ; t=t->next,ind++)
	{
		if( t->data == x )  
			return ind;
	}
	return(-1);

}
Node *insert(Node *start,int x,int ind)
{
	Node *NN,*t=start;
	int i=0;
	NN = new Node;
	NN->data = x;
	NN->next = NULL;
	if(t == NULL)  return NN;
	if(ind == 0)
	{
		NN->next = t;
		return NN;
	}
	for( ; t->next && i!=ind-1 ; i++,t=t->next);
	if(t->next == NULL)
	{
		t->next = NN;
		return start;
	}
	NN->next = t->next;
	t->next = NN;
	return start;
}

Node *del(Node *start,int ind)
{
	Node *ptr=NULL,*temp=start;
        if(start==NULL) return start;
	if(start->data == ind)  
	{
		start=start->next;
		delete temp;
		return start;
	}
	for( ;temp->next->data != ind; temp=temp->next);
	ptr=temp->next;
	temp->next=temp->next->next;
	delete ptr;
	return start;
}	
Node *sort(Node *start)
{
	int t=0;
	
	Node *t1=NULL,*t2=NULL;
	for( t1=start ;  t1  ; t1=t1->next)
		for( t2=t1->next ; t2 ; t2=t2->next )
		{
			if( t1->data > t2->data )
			{
				t=t1->data;
				t1->data = t2->data;
				t2->data = t;
			}
		}
	return start;
}
out *Insert(out *start,char charec)
{
	out *newnode,*temp;
	newnode=new out;
	newnode->ch=charec;
	newnode->next=NULL;
        if(start == NULL ) return newnode;
	for( temp=start ; temp->next ; temp=temp->next);
	temp->next=newnode;
	return start;
}
int main()
{
	Node *start=NULL,*temp=NULL;
	int x=0,ind=0,size=0;
	out *t=NULL;
	char ch='\0';
	for(;1;)
	{
		cin >> ch;
		if(ch == 'X') 
		{
			print(t);
			break;
		}
		switch(ch)
		{
			case 'I':
				cin >> x;
				cin >> ind;
				start=insert(start,x,ind);
				size++;
				break;
			case 'F':
				cin >> x;
				t=Insert(t,find(start,x));
				t=Insert(t,39);
				break;
			case 'D':
				cin >> ind;
				start=del(start,ind);
				break;
			case 'S':
				start=sort(start);
				break;
			case 'R':
				start=reverse(start);
				break;
			case 'C':
				clear(start);
				break;
			case 'P':
				temp = start;
				for( ;temp; t=Insert(t,temp->data),temp=temp->next);
				t=Insert(t,39);
				break;
		}
	}
	return 0;
}
