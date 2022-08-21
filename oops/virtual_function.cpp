#include<iostream>
using namespace std;

/*
1. A virtual function is a member function 
which is declared within a base class and is re-defined (overridden) by a derived class.
2. Virtual functions cannot be static.
3. A virtual function can be a friend function of another class.
4. Virtual functions should be accessed using pointer or reference of base class type to achieve runtime polymorphism.
5. They are always defined in the base class and overridden in a derived class. 
*/

class base
{
    public:
    virtual void display()
    {
        cout << "This is the base class" << endl;
    }
};

class derived : public base
{
    public:
    
    void display()
    {
        cout << "This is the derived class" << endl;
    }
};

int main()
{
    base* ptr_base = new derived();
    ptr_base->display();
    // without virtual keyword - it displays " base class display "
    // with keyword - it displays "derived class display" 
    return 0;
}