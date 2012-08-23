#include <iostream>	
using namespace std;	
 
class node 
{
	public:
		int data;
		node *next;
};

class HashTable
{
	private:
		node *start[101];
		int num;
	public:
		// Constructor initializing all pointers to 'NULL'
		HashTable()
		{   
			num = 101;
			for( int i=0 ; i<num ; start[i]=NULL,i++ );  
		}
		// Destructor
		~HashTable() {}
		void insert(int element)
		{
			node *s,*t,*NewNode;
			s = start[element % num];
			NewNode=new node;
			NewNode->data=element;
			NewNode->next=NULL;
			if(s==NULL)   { start[element % num]=NewNode; return;}
			for(t=s ;t->next;t=t->next);
			t->next = NewNode;
			return;
		}
		int del(int element)
		{
			node *temp=NULL,*s=start[element%num];
			int i=1;
			if(!s) 
				return -1;
			if(s->data == element)  
				return 1;
			for(   ; s->next ; s=s->next,i++ )
			{
				if(s->next->data == element)
				{
					temp=s->next;
					s->next = temp->next;
					delete temp;
					return i;
				}
			}
			if(! s->next) return(-1);
		}
		int search(int element)
		{
			node *s=start[element % num];
			int i=1;
			if(!s)   return -1;
			for(   ; s ; s=s->next,i++ )
				if(s->data == element)
					return i;
			return -1;
		}

};

int main()
{
	HashTable T;
	int n;
	char ch;
	for( cin>>ch ; 1 ;   )
	{
		switch(ch)
		{
			case'i':cin>>n;
				T.insert(n);
				break;
			case'd':cin>>n;
				cout<<T.del(n)   <<endl;
				break;
			case's':cin>>n;
				cout<<T.search(n)<<endl;	
				break;
			case'x':return 0;
			default:cout<<"Invalid Input\n";
				break;
		}
		cin>>ch;
	}
}
