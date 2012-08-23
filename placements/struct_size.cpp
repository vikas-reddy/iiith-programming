#include<iostream>

struct A {
    int a;
    char b;
    char c;
    short int d;
};

struct B {
    char b;
    char c;
    int a;
    short int d;
};

struct C {
    int a;
    char b;
};

union D {
    double a;
    struct C b;
};

class E {
};

int main()
{
    //printf("A=%d; B=%d; C=%d; D=%d\n", sizeof(struct A), sizeof(struct B), sizeof(struct C), sizeof(union D));
    printf("%d\n", sizeof(E));
    return 0;
}
