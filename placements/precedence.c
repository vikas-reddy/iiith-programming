#include<stdio.h>

int main(){
	int i,j;
	i=0, j=1;
	//i = i - i + 2*i++;
    i = i++ * --j;
	printf("i = %d; j = %d\n",i, j);
	return 0;
}
