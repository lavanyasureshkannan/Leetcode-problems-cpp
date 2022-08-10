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
FUNTION OVERRIDING -> Functions with the same name but with different paramateres can be overridden 
*/

class vehicle
{
    public: 
    void display()
    {
        cout << " this is a vehicle" << endl;
    }
};


void display(int num1)
{
    cout << " display the num " << num1 << endl;
}

void display(int num1, double num2)
{
    cout << " diplay the num and the double values: " << num1 << "," << num2 << endl;
}

void display(float num1, string st)
{
    cout << "display the number followed by the string " << num1 << " and " << st << endl;
}

int main()
{
    // the function inside the class can be overrriden by the same function name during the run time

    vehicle vehicle1;
    vehicle1.display();
    // same function name with different paramters but executed differently during the run time
    display(5);
    display(6,23125);
    display(6.6, "ppl");
    return 0;
}