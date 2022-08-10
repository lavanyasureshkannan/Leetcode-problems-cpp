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

/*  H      


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
class bus : public Vehicle
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