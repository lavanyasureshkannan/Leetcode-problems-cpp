#include<iostream>
using namespace std;

/*
    In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object.
    
*/


class rectangle
{
    int length;
    int* width;

    public:
    rectangle()
    {
        width = new int;
    }

    void set_dimensions(int l, int w)
    {
        length = l;
        *width = w;

    }
    void display()
    {
        cout << length << " " << *width << endl;
    }
    // creating parameterized constructor and deep copy
    // class name (const class name& obj) => copy constructor 
    rectangle(rectangle& n)
    {
        length = n.length;
        width = new int;
        *width = *(n.width);
    }
    // destructors
    ~rectangle()
    {
        delete width;
    }
};


int main()
{
    rectangle r1;
    r1.set_dimensions(10,20);
    r1.display();

    rectangle r2 = r1;
    r2.display();
    return 0;
}
