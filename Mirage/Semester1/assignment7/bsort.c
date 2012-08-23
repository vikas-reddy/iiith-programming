#include"bsort.h"
#include<stdio.h>
void bsort(void *base,int nmemb,int size ,int (*compar)(const void *,const void *))
{
	char temp,*a;
	int p,q,r;
	a=(char*)base;
	for(p=0;p<nmemb*size;p=p+size)
		for(q=0;q<(nmemb-1)*size;q=q+size)
		{	
			if(compar(a+q,a+q+size)>0)
			{
				for(r=0;r<size;r++)
				{
					temp=*(a+q+r);
					*(a+q+r)=*(a+size+r+q);
					 *(a+size+r+q)=temp;
				}
			}
		}
}

