#include <iostream>
using namespace std;

class BaseClass
{
	private:
		int BaseData;
	public:
		BaseClass()
		{
			cout << "Base Class Constructor" << endl;
		}
		virtual ~BaseClass()
		{
			cout << "Base Class Destructor" << endl;
		}
};

class DerivedClass: public BaseClass
{
	private:
		int DerivedData;
	public:
		DerivedClass()
		{
			cout << "Derived Class Constructor" << endl;
		}
		~DerivedClass()
		{
			cout << "Derived Class Destructor" << endl;
		}
};

class SatishBase
{
	private:
		int data;
	public:
		virtual void function()
		{
			cout << "something" << endl;
		}
};

class SatishDerived1: public SatishBase
{
	public:
		virtual void function()
		{
			cout << "something Derived1" << endl;
		}
};

class SatishDerived2: public SatishBase
{
	public:
		virtual void function()
		{
			cout << "something Derived2" << endl;
		}
};

class SatishDerived3: public SatishDerived1, SatishDerived2
{
	public:
};

int main()
{

	/*
	BaseClass *b;
	DerivedClass *d;

	b = new DerivedClass;

	cout << "b created" << endl;

	delete b;
	return 0;
	*/

	SatishDerived3 D;
	D.function();
	return 0;
}
