#include <iostream>
using namespace std;

class list
{
	public:
		int n;
		list *next;
		
};

list *Insert(list *start,int data)
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

void print(list *start)
{
	list *t=start;
	for(   ;t; cout << t->n << " ",t=t->next);
	cout << endl;
	return;
}

list *intersection(list *a,list *b)
{
	list *temp1=a,*temp2=b,*ptr=NULL;
	for(temp1=a ; temp1 ; temp1=temp1->next)
		for(temp2=b ; temp2 ; temp2=temp2->next)
			if(temp2->n == temp1->n)
				ptr = Insert(ptr,temp1->n);
	return ptr;
}

int main()
{
	list *s1=NULL,*s2=NULL,*ptr=NULL;
	int i=0;
	for(;1;)
	{
		cin >> i;
		if(i==-1) break;
		s1 = Insert(s1,i);
	}
	for(i=0;1;)
	{
		cin >> i;
		if(i==-1) break;
		s2 = Insert(s2,i);
	}
	cout << "Intersection= ";
	print(intersection(s1,s2));
}
