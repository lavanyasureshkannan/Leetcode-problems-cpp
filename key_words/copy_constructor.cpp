#include<iostream>
using namespace std;

/*
    COPY CONSTRUCTOR: It is a member function inside the class which initializes an object by another object of the same class.
    1. It is used initialise a new object from the existing object.
    2. classname(const classname& object)
    3. The process of initiating the objects through a copy constructor is called copy initialization.

    Notes:
    1. copy constructor can be made private.
    2. We are using const here so that the objects wont be modified at any cause.
*/


class base
{
    int m_num;
public:
    void set_num(int num)
    {
        m_num = num;
    }
    // deafult constructor
    base()
    {

    }
    // copy constructor
    base(const base& b1)
    {
        m_num = b1.m_num;
    }
    void display()
    {
        cout << m_num << endl;
    }

}; 

int main()
{
    base b1;
    b1.set_num(10);
    b1.display();

    // calling the copy constructor
    base b2(b1);
    b1.display();
    return 0;
}