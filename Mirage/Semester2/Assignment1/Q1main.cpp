#include<iostream>
#include"list.h"
using namespace std;

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
