#include<iostream>
using namespace std;

int main()
{
	int a=0, b=0, temp=0;
	cin >> a >> b;
	while(a%b != 0)
	{
		temp = a;
		a = b;
		b = temp % b;
	}
	cout << "GCD is " << b << endl;
	return 0;
}
