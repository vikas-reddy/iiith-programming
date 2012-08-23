#include <iostream>
using namespace std;

class list
{
	public:
		int n;
		list *next;
		list* remDUP(list *start);
		int exist(list *start,list *temp,int data);
		list *Insert(list *start,int data);
		void print(list *start);
};

int list::exist(list *start,list *temp,int data)
{
	list *t=start;
	for(    ; t!=temp->next ; t=t->next)
	{
		if(t->n == data) return 1;
	}
	return 0;
}

list *list::Insert(list *start,int data)
{
	list *NN,*temp=start;
	NN = new list;
	NN->n = data;
	NN->next = NULL;
	if(temp == NULL)
		return NN;
	for(  ;temp->next;temp=temp->next);
	temp->next = NN;
	return start;
}

list* list::remDUP(list *start)
{
	list *temp=start, *ptr=NULL;
	for( ;temp->next; temp=temp->next)
	{
		/*if(temp->next->next==NULL && temp->n == temp->next->n)
		{
			ptr= temp->next;
			temp->next = NULL;
			delete ptr;
			return 0;
			
		}*/
		if(exist(start,temp,temp->next->n) )
		{
			ptr = temp->next;
			temp->next = temp->next->next;
			delete ptr;
		}
	}
	return start;
}

void list::print(list *start)
{
	list *t=start;
	for(  ;t; cout << t->n << " ", t=t->next);
	cout << endl;
}

int main()
{
	list *temp;
	list *start=NULL;
	int i=0;
	for(;1;)
	{
		cin >> i;
		if(i == -1)  break;
		start = temp->Insert(start,i);
	}
	start = temp->remDUP(start);
	temp->print(start);
}
