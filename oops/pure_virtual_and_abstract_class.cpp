#include<iostream>
using namespace std;

/*
ABSTRACT CLASS 
1. Abstract class is a class with atleast one pure virual function in it.
2. when you declare a pure virtual function inside a class then all the derived class from that base class will have its own implementation.
*/

class base
{
    public:
    // a virtual function = 0 -> pure virtual function
    virtual void display() = 0;
};

class derived : public base
{
    public:
    
    void display()
    {
        cout << "This is the derived class" << endl;
    }
};

class derived_second : public base
{
    public:

    void display()
    {
        cout << "This is the second derived class" << endl;
    }
};

int main()
{
    // without virtual keyword - it displays " base class display "
    // with keyword - it displays "derived class display" 
    base* ptr_base = new derived();
    ptr_base->display();
    
    base* ptr_base_two = new derived_second();
    ptr_base_two->display();
    return 0;
}