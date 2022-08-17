#include<iostream>
using namespace std;

/*
DESTRUCTOR -> Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed. 
Meaning, a destructor is the last function that is going to be called before an object is destroyed.
It is not possible to define more than one destructor. 
The destructor is only one way to destroy the object create by constructor. Hence destructor can-not be overloaded.
It cannot be declared static or const.
The destructor does not have arguments.
It has no return type not even void.

*/

class test
{
    public:
    int x;

    test() 
    {
        cout << "contructor initiated" << endl;
    }
    ~test()
    {
        cout << "destructor initiated" << endl;
    }
};


int main()
{
    test t1;
    return 0;
}