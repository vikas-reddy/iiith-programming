#include <iostream>
using namespace std;

int factorial(int n)
{
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;

	int result=1;

	for(int i=1; i<=n; i++)
		result *= i;

	return result;
}

int main()
{
	int n;
	// int, char, float, double, bool
	// signed, unsigned, short, long
	// static, explict, explicit, void
	
	cin >> n;

	cout << factorial(n) << endl;
	
	return 0;
}
