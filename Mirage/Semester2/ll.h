#include<iostream>
using namespace std;
class List 
{
	public:
		int data;
		List *next;
		//List *prev;
};
List *insert(List *start,int num)
{
	List *NN,*temp=start,*ptr;
	NN = new List;
	NN -> data = num;
	NN -> next = NULL;
	if( start == NULL)  return NN;
	for(   ; temp -> next != NULL ; temp = temp -> next );
	temp -> next = NN;
	return start;
}
List *merge(List *s1,List *s2)
{
	List *s3,*pres;
	if(s1->data < s2->data)
	{
		s3=s1;
		s1=s1->next;
	}
	else 
	{
		s3=s2;
		s2=s2->next;
	}
	pres=s3;
	while(s1!=NULL && s2!=NULL)
	{
		if(s1->data < s2->data)
		{
			pres->next=s1;
			s1=s1->next;
			pres=pres->next;
		}
		else 
		{
			pres->next=s2;
			s2=s2->next;
			pres=pres->next;
		}
	}
	return s3;

}
void print(List *start)
{
	List *temp=start;
	for(  ; temp!=NULL ; cout << temp->data << " " , temp=temp->next);
        cout << endl ;
}
