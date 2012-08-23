#include<stdio.h>
#include"mylist.h"
node *reverse(node *start)
{
	node *prev,*temp,*cur;
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
node * recReverse(node *prev,node *cur)
{
	node *temp,*temp1;
	if(cur->next==NULL)
		return cur;
	temp1=recReverse(prev,cur->next);
	cur->next->next=cur;
	cur->next=NULL;
	return temp1;
}	
void print(node *start)
{
	node *temp;
	for( temp=start; temp ; printf("%d  ",temp->data),temp=temp->next);
}

