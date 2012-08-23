#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *next;
}node;

node* Insert(node *start, int value)
{
	node *NewNode;
	NewNode = (node *)malloc(sizeof(node));
	NewNode->info = value;
	NewNode->next = start;

	return NewNode;
}

void Print(node *start)
{
	if(!start)
		return;

	for( ;start; start=start->next)
		printf("%3d ", start->info);
	printf("\n");
	return;
}

void Concatenate(node *A, node *B)
// Concatenating two lists without using additional variable.
{
	if(!A || !B)
		return;

	if(!A->next)
	{
		A->next = B;
		return;
	}

	Concatenate(A->next, B->next);
	B->next = A->next;
	A->next = B;
	return;
}

int main()
{
	node *A=NULL, *B=NULL;
	int i=0;

	for(i=0; i<10; i++)
	{
		if(i%2 == 0)
			A = Insert(A, rand()%1000);
		B = Insert(B, rand()%1000);
	}

	Print(A);
	Print(B);

	Concatenate(A, B);

	Print(A);
	return 0;
}
