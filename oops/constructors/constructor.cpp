#include<iostream>

// CONTRUCTOR -> Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
// It is used to initialize the data members of new objects generally.
// Constructor does not have a return value, hence they do not have a return type.
// Three types of constructors
// 1. DEFAULT CONSTRUCTOR, COPY CONSTRUCTOR, PARAMETERISED CONSTRUCTOR




// DEFAULT CONSTRUCTOR
class construct
{
    public:
    int a , b;

    // create a constructor and set the parameters
    construct()
    {
        a = 10;
        b = 20;
    }
    // display function
    void display()
    {
        std::cout << a << "," << b << std::endl;
    }

};


int main()
{
    // create an object
    construct c1;
    // call the display function
    c1.display();
    return 0;
}