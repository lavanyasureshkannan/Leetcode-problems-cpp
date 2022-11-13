#include<iostream>
using namespace std;

/*
Lvalue -> Something that has its own address in the memory
Rvalue -> Something that resides on the right side of the operator.
*/

int add(int a, int b)
{
    return a+b;
}

class base
{
    public:
    void print()
    {
        cout << "inside base class" << endl;
    }
};

int main()
{
    int i = 5; // i is lvalue and 5 is rvalue
    int j = i+1; // j is lvalue and i+1 is rvalue
    int x = add(2,3); // x is lvalue and the function which returns is rvalue
    base b1;
    b1 = base(); // b1 lvalue and base() rvalue
    return 0;
}