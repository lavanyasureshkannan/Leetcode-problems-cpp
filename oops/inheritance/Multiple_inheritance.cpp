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

/*  MULTIPLE INHERITANCE -> sub class can be derived from more than one base class 

    Base class          second base class
        \               /
          Derived class
*/


// Base class 1
class Vehicle
{
    public:
    void display()
    {
        cout << "This is a vehicle -> Display under base class" << endl;
    }
};


// Base class 2
class Fourwheel
{
    public:
    void display_second()
    {
        cout << "This is a four wheeler -> Display under second base class" << endl;   
    }
};


// Sub class derived from base class 1 and base class 2
class Car : public Vehicle, public Fourwheel
{
    public:
    void display_sub()
    {
        cout << "This is a car -> display under sub class" << endl;
    }
};


int main()
{
    Car car1;
    car1.display();
    car1.display_second();
    car1.display_sub();
    return 0;
}