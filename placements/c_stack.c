#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *S=NULL;

struct node* push(struct node* head, int value)
{
	struct node *NewNode;
	NewNode = (struct node*)malloc(sizeof(struct node));

	NewNode->value = value;
	NewNode->next  = head;
	return NewNode;
}

int pop(struct node * head)
{
	int value = head->value;
	struct node *Top_Node;
	Top_Node = head;
	head = head->next;
	free(Top_Node);
	return value;
}

int main()
{
	S = push(S, 444);
	S = push(S, 555);
	S = push(S, 666);

	pop(S);

	printf("%d\n", pop(S));
	return 0;
}
