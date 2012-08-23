#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class out
{
	public:
		int ch;
		out *next;
};

Node *insert(Node *start,int x,int ind);
int find(Node *start,int x);
Node *del(Node *start,int ind);
Node *sort(Node *start);
Node *reverse(Node *start);
Node *clear(Node *start);
void print(out *start);
out *Insert(out *start,char charec);
//void print2(Node *start);


