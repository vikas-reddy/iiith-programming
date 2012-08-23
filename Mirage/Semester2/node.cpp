#include <iostream>
#include "node.h"
using namespace std;
int node::getdata()
{  
	return data;
}
node *node::getnext()
{
	return n;
}	
node *node::getprev()
{
	return p;
}
void node::putdata(int num)
{
	data=num;
}
void node::putnext(node *N)
{
	n=N;
}
void node::putprev(node *P)
{
	p=P;
}
node *Insert(node *start,int num)
{
	node *NN;
	NN=new node;
	NN->putdata(num);
	NN->putprev(NULL);
	NN->putnext(start);
	if(NN->getnext() != NULL)
	{
		(NN->getnext())->putprev(NN);
	}
	return NN;
}
void print(node *start)
{
	node *t=start;
	for( ; t!=NULL ; cout << t->getdata() << " " , t=t->getnext());
	cout << endl;
}
void print2(node *temp)
{
	for( ;temp!=NULL ; cout << temp->getdata() << " "   
			                           ,   temp=temp->getprev()  );
	cout << endl;
	
}
node *incr_sort(node *st)
{
	
	
	node *temp1=st,*temp2=NULL;
	int state=0,t;
	
	for(    ; temp1!=NULL ;  temp1=temp1->getnext() )
	{
		
		for( state=0 , temp2=temp1->getnext() 
				; temp2!=NULL ; 
				          temp2=temp2->getnext())
		{
			if(temp1->getdata() > temp2->getdata()) 
			{
				state=1;
				break;
			}
		}
		if(state)
		{
			/*(temp1->getprev())->putnext(temp2);
			(temp1->getnext())->putprev(temp2);
			(temp2->getprev())->putnext(temp1);
			(temp2->getnext())->putprev(temp1);
			temp1->putnext(temp2->getnext());
			temp2->putnext(temp1->getnext());
			temp1->putprev(temp2->getprev());
			temp2->putnext(temp1->getnext());*/
			
			
			t=temp1->getdata();
		        temp1->putdata(temp2->getdata());	
			temp2->putdata(t);
			temp2=temp2->getnext();
		}
	}
	return st;
}	

	

	

