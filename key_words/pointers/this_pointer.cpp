#include<iostream>
using namespace std;


/*
    THIS POINTER
    Every object have an access to its own memory address using a pointer called this pointer.
    This pointer is a const pointer.
    It is passes as a hidden argument to all non-static members and memeber functions.
*/

class base
{
    int a;    
public:
    void SetA(int a)
    {
        // It is used to retrieve the object a which is hidden by the local variable a
        this->a = a;
    }
    void print()
    {
        cout << a << endl;
    }

};

int main()
{
    base b1;
    b1.SetA(10);
    b1.print();
    return 0;
}