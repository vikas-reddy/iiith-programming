#include<iostream>
using namespace std;

class A {
    char ch;
    public:
};

class B: public A {
    public:
        virtual void func(int x) =0;
        virtual void func2(int x) =0;
        virtual void func3(int x) =0;
        virtual void func4(int x) =0;
};


int main()
{
    cout << sizeof(A) << " " << sizeof(B) << endl;
    return 0;
}
