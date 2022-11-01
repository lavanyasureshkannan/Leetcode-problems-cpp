#include<iostream>
using namespace std;

/*
    POLYMORPHISM -> simple means exists in more than one form. 
    The entity behaves differently at different scenarios
    
    Two types of polymorphism -> Compile time polymoriphism, Run time polymorphism  
    There are three ways you can achieve polymorphism
    
    COMPILE TIME 
    1. FUnction Overloading
    2. Operator Overloading

    RUNTIME 
    1. Function Overriding
    2. Virtual Functions 
*/

/*
VIRTUAL FUNCTION -> A virtual function is a member function in the base class that we expect to redefine in derived classes.
They are declared inside the class and defined in the derived class during runtime
*/

class Vehicle
{
    public:
    void virtual display();
};

class car : public Vehicle
{
    public:
    void display()
    {
        cout << " The vehicle is the subclass is car " << endl;
    }
};

int main()
{
    // create an objct
    car car1;
    //create a pointer that points to the object created
    Vehicle* car_ptr = &car1;
    // calls the member function
    car_ptr->display();
    return 0;

}





