#include <iostream>
using namespace std;

class node
{
	public:
	char ch;
	node *next;
};

void print(node *start)
{
	node *t=start;
	for(  ;t; cout << t->ch ,t=t->next);
}
node *insert(node *start,char charec)
{
	node *newnode,*temp;
	newnode=new node;
	newnode->ch=charec;
	newnode->next=NULL;
        if(start == NULL ) return newnode;
	for( temp=start ; temp->next ; temp=temp->next);
	temp->next=newnode;
	return start;
}
int main()
{
	node *ptr=NULL,*start=NULL;
	char str[200];
	int j=1;
	cin.getline(str,200);
	for(int i=0 ; str[i]!='\0' ; start=insert(start,str[i]),i++)
	{
		if(str[i] == ' ')
		{ 
			j++;
			if(str[i+1] == ' ' ) j--;
		}
	}
	node *a[j];
	node *t=NULL;
	a[0]=start;
	int i=1;
	for(node *t=start ; t ; t=t->next)
		if(t->ch==' ')
			if(t->next && t->next->ch!=' ')
			{
				a[i]=t->next;
				i++;
			}
	for(i=0 ; i<j ; i++)
	{
		for(t=a[i] ; t->next  ; t=t->next)
                if(t->next->ch==' ')
		{
			t->next=NULL;
			break;
		}
	}
	for(i=j-1 ; i>=0 ; i--)
	{
		print(a[i]);
		cout << " ";
	}
	cout << '\n';
}
