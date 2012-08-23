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
node *insert( node *start,int N)
{
	 node *new,*ptr;
	new=(node *)malloc(sizeof(node));
	new->data=N;
	ptr=start;
	if(ptr==NULL) 
	{
		new->next=NULL;
		start=new;
		return start;
	}
	if(ptr->data > N) 
	{
		new->next = ptr;
		start=new;
		return start;
	}
	for(  ;ptr->next!=NULL  &&  ptr->next->data < N;  ptr=ptr->next );
	if(ptr->data  <  N)
	{
		new->next = ptr->next;
		ptr->next= new;
	}
	return start;
}
main()
{
	int i;
	node *start=NULL;
	for(i=0;i<5;i++)
		start=insert(start,rand()%100);
	print(start);
	printf("\n");
	start=reverse(start);
	print(start);
}
