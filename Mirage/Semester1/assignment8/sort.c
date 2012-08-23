#include <stdio.h>
#include <stdlib.h>
struct node
{
	int n;
	struct node *next;
	
};
struct node *selsort(struct node *start)
{
}
struct node *insert(struct node *start, int x)
{
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->n=x;
	newnode->next=NULL;
        if(start == NULL ) return newnode;
	for( temp=start ; temp->next ; temp=temp->next);
	temp->next=newnode;
	return start;
}
main()
{
	int n=0,i=0,j=0,k=0;
	struct node *s1=NULL;
	for(i=0 ; i<10 ; s1=insert(s1,rand()%100),i++);
	for( ; s1 ; printf("%d ",s1->n),s1=s1->next);

}
		
