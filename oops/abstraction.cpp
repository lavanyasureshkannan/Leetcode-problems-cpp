#include <iostream>
using namespace std;

/*
    ABSTRACTION -> Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
    get and set method -> declare the variable in private and get the variable inside public
*/

class Abstraction
{
    private:
    int a, b;

    public:
    // setting the private value
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
    // getting the private value
    void display()
    {
        cout << a;
        cout << b;
        
    }

};

int main()
{
    // declare an object
    Abstraction obj1;
    // set the x value
    obj1.set(10,15);
    // get the value
    obj1.display();
    return 0;
}