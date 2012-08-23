#include <stdio.h>

int main()
{
	void func(int, int);
	int i=10;
	func(i, i++);
	return 0;
}

void func(int p, int q)
{
	if(p > 50)
		return;
	p += q;
	func(p, q);
	printf("%d ", p);
	return;
}
