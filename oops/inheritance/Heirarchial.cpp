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

/*  HYBID INHERITANCE -> combination of heirarchial and multiple inheritance

    Base class          
        |  
    base class 2
    /       \
sub class1   sub class2          


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

// base class 2
class fourwheel
{
    public:
    void display_one()
    {
        cout << "This is a fourhweel -> display under second base class" << endl;
    }
}; 

// subclass 1
class car : public Vehicle
{
    public:
    void display_second()
    {
        cout << "This is a four wheeler -> Display under derived class" << endl;   
    }
};

// second sub class
class bus : public Vehicle, public fourwheel
{
    public:
    void display_sub()
    {
        cout << "This is a car -> display under second sub class" << endl;
    }
};


int main()
{
    bus bus1;
    bus1.display();
    bus1.display_one();
    bus1.display_sub();
    return 0;
}