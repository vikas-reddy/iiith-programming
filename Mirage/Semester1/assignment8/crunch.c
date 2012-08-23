#include <stdio.h>
#include <stdlib.h>
struct node
{
	char ch;
	struct node *next;
};
struct node *insert(struct node *start, char charec)
{
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->ch=charec;
	newnode->next=NULL;
        if(start == NULL ) return newnode;
	for( temp=start ; temp->next ; temp=temp->next);
	temp->next=newnode;
	return start;
}
struct node *rem(struct node *start,char charec)
{
	struct node *ptr=NULL,*temp=start;
        if(start==NULL) return start;
	if(start->ch==charec)  
	{
		start=start->next;
		free(temp);
		return start;
	}
	for( ;temp->next->ch != charec; temp=temp->next);
	ptr=temp->next;
	temp->next=temp->next->next;
	free(ptr);
	return start;

}
struct node *crunch(struct node *s1,struct node *s2)
{
	struct node *temp1=s1,*temp2;
	for(  ; temp1 ;temp1=temp1->next)
		for( temp2=s2 ; temp2 ; temp2=temp2->next )
			if(temp1->ch == temp2->ch) 
			{
				s1=rem(s1,temp1->ch);	
				break;
			}
	return s1;
}
/*struct node *crunch(struct node *s1,struct node *s2)
{
	struct node *temp1=s1,*temp2,*ptr=NULL;
	for(  ; temp1 ; )
	
		for( temp2=s2 ; temp2 ; temp2=temp2->next )
		
		{	if(temp1->ch == temp2->ch) 
			{
				ptr=temp1;
				temp1=temp1->next;
				free(ptr);
				break;
			}
			else 
			      temp1=temp1->next;
			continue;
		}
	return s1;
}*/
main()
{
	int i=0,j=0,k=0;
	char a[200],b[100];
	struct node *s1=NULL,*s2=NULL;
	scanf("%[^\n]",a);
	scanf(" %[^\n]",b);
	for(i=0 ; a[i]!='\0' ; i++)           s1=insert(s1,a[i]);
	for(i=0 ; b[i]!='\0' ; i++)           s2=insert(s2,b[i]);
	s1=crunch(s1,s2);
	for(    ; s1  ; printf("%c",s1->ch), s1=s1->next);
	printf("\n");
}
		
