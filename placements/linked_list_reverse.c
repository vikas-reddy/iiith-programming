#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node* next;
	int value;
} Node;

Node* Insert(Node *head, int val)
{
	Node *NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->next = NULL;
	NewNode->value = val;

	if(!head)
		return NewNode;
	NewNode->next = head;
	return NewNode;
}

void Print(Node *head)
{
	Node *start = head;
	for(  ;start; start=start->next)
		printf("%d ", start->value);
	printf("\n");
	return;
}

Node* Reverse(Node *head)
{
	Node *start = head, *temp=NULL;
	Node *NewList = NULL;
	while(start)
	{
		temp = start->next;
		start->next = NewList;
		NewList = start;
		start = temp;
	}
	return NewList;
}

Node* RecursiveReverse(Node *head)
{
	if(!head || !head->next)
		return head;

	Node *temp=RecursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

Node* VimjamRecursiveReverse(Node *p)
{
	if(!p->next || !p)
		return p;
	Node *tail = p->next;
	Node *rev  = VimjamRecursiveReverse(p->next);
	Node *head = rev;
	tail->next = p;
	p->next = NULL;

	return head;
}


int main()
{
	Node *head=NULL;
	int i=0, X=0;
	for(i=0; i<20;  X = rand()%1000,
			head=Insert(head,X), 
			i++);
	Print(head);
	head = VimjamRecursiveReverse(head);
	Print(head);
	return 0;
}
