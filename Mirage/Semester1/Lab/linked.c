#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *next;
};
struct node *reverse(struct node *start)
{
	struct node *temp;
	struct node *current;
	struct node *prev;
	prev=NULL;
	current=start;
	temp=start->next;
	while(current)
	{
		current->next=prev;
		prev=current;
		current=temp;
		temp=temp->next;
	}
	return (current);
}
void *insert(struct node *start,int N)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->n=N;
	newnode->next=start;
	start = newnode;
}
main()
{
	int i=0,num=0;
	struct node *start;
	start=NULL;
	for(i=0 ; i<10 ; i++)
	{
		scanf("%d",&num);
		insert(start,num);
	}
	start=reverse(start);
	for(i=0 ; i<10 ; i++)
	{
		printf("%d ",start->n);
		start=start->next;
	}
	printf("\n");
}
