#include<iostream>
using namespace std;
class node 
{
	private:
	int data;
	node *p;
	node *n;
	public:
	int getdata();
	node *getnext();
	node *getprev();
	void putdata(int num);
	void putnext(node *N);
	void putprev(node *P);
};
node *Insert(node *start,int num);
void print(node *start);
void print2(node *temp);
node *incr_sort(node * st);
	
