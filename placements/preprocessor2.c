#include <stdio.h>
#define f(a,b) a##b
#define g(a)   #a
#define h(a) g(a)

#define sqrt(x) x*x
int main()
{
	printf("%s\n",h(f(1,2)));
	printf("%s\n",g(f(1,2)));
	printf("%d\n", sqrt(sqrt(sqrt(2))));
	return 0;
}
