#include <iostream>
using namespace std;

class Base 
{
	private:
		int var;
	public:
		virtual void func() =0;
};

class Derived: public Base
{
	private:
		char ch;
	public:
		void func()
		{
			cout << "func in Derived" << endl;
		}
};

int main()
{
	Base *b;
	Derived d;

	b = new Base;

	b->func();
	return 0;
}

