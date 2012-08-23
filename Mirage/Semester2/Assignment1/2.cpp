#include<iostream>
using namespace std;

class node 
{
	public:
	char string[100];
	node *next;
};
int main()
{
	int n=0,k=0,j=0,i=0;
	cin >> k >> n;
	char array[100];
	node *a[n],*ptr=NULL,*curr=NULL;
	i=0;
	while(  i<n  )
	{
		a[i]=new node;
		cin >> array;
		j=0;
		while( array[j] != '\0')
		{
			a[i]->string[j] = array[j];
			j++;
		}
		a[i]->string[j] = '\0';
		i++;
	}
	a[n-1]->next = a[0];
	curr=a[0];
	i=0;
	while( i<n-1 )
	{
		a[i]->next=a[i+1];
		i++;
	}
	if(k==1)
	{
		i=0;
		while(  i<n )
		{
			cout<<a[i]->string<<" ";
			i++;
		}
		cout << endl;
		return 0;
	}
	i=0;
	while( i<n )
	{
		j=1;
		while( j!=k-1 )
		{
			curr=curr->next;
			j++;
		}
		ptr = curr->next;
		curr->next=ptr->next;
		cout << ptr->string << " ";
		delete ptr;
		curr = curr->next;
		i++;
	}
	cout << endl;
	return 0;
}
	

