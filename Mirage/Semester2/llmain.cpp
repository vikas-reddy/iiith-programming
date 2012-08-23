#include<iostream>
#include"ll.h"
using namespace std;
int main()
{
	int n=0;
	List *a=NULL,*b=NULL;
	for( ; n!=-1 ;) 
	{
		cin >> n;
		if(n!=-1) a=insert(a,n); 
	}
	for(n=0 ; n!=-1 ;) 
	{
		 cin >> n;
		if(n!=-1) b=insert(b,n); 
	}
	print(merge(a,b));
}
