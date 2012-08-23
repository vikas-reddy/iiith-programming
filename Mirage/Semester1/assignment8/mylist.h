#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};

typedef struct node node;

void print(node *start);

node * recReverse(node *prev,node *cur);

node * reverse(node *start);
