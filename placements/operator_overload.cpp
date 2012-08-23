#include <iostream>
#include <stdlib.h>
using namespace std;

class Data
{
	public:
		int x, y;
		int array[10];


		Data()
		{
			for(int i=0; i<10; i++)
				array[i] = rand()%1000;
		}
		int operator[](int a, int b)
		{
			return(b + array[a]);
		}
		void printArray()
		{
			cout << "Elements are ";
			for(int i=0; i<10; i++)
				cout << array[i] << " ";
			cout << endl;
		}
};

int main()
{
	Data a;
	a.printArray();

	cout << a[4, 44] << endl;
	return 0;
}
