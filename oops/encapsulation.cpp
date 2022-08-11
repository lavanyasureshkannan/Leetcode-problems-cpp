#include <iostream>
using namespace std;

/*
    ENCAPSULATION -> When you dont want to declare things in public, you can declare it in private and not want to explicitly mention it you will do this.
    get and set method -> declare the variable in private and get the variable inside public
*/

class Encapsulation
{
    private:
    int a;

    public:
    // setting the private value
    void set(int x)
    {
        a = x;
    }
    // getting the private value
    int get()
    {
        cout << a;
        return a; // this function will eventually get you the variable declared under private
    }

};

int main()
{
    // declare an object
    Encapsulation obj1;
    // set the x value
    obj1.set(10);
    // get the value
    obj1.get();
    return 0;
}