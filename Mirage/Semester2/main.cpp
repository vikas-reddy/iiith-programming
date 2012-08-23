#include "node.h"
#include<iostream>
using namespace std;
int main()
{
	int i=0;
	node *t,*start=NULL;
	for( i=0 ; i<10 ; start=Insert(start, rand()%100 ),i++);
        for( t=start ; t->getnext()!=NULL ; t=t->getnext());
	print(start);
	start=incr_sort(start);
	print(start);
	//cout << endl << t->getdata() << endl <<endl;
	return 0;
}
		
