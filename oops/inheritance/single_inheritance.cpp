#include<iostream>
using namespace std;

/*
 INHERITANCE
 1. MODES OF INHERITANCE -> public (can be accessed everywhere-> both inside and outside the class)
                         -> protected (can be accessed in every subclass)
                         -> private (cannot be accessed anywhere except parent class)

 2. TYPE OF INHERITANCE  -> Single Inheritance
 `                       -> Multi-level Inheritance
                         -> Multiple Inheritance
                         -> Heirarachial Inheritance
                         -> Hybrid Inheritance
*/

/*  SINGLE INHERITANCE 

    Base class
        |
    Derived class
*/

class Vehicle // base class
{
    public:
    void dispaly()
    {
        cout << "Display under base class" << endl;
    }

};

class Car : public Vehicle
{
    public:
    void sub_display()
    {
        cout << "Display under sub class" << endl;
    }

};

int main()
{
    // create an object from subclass and accessing the function from both main and sub class created
    Car car1;
    car1.dispaly();
    car1.sub_display();
    return 0;
}