#include<iostream>

// CONTRUCTOR -> Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
// It is used to initialize the data members of new objects generally.
// Constructor does not have a return value, hence they do not have a return type.
// Three types of constructors
// 1. DEFAULT CONSTRUCTOR, 2. COPY CONSTRUCTOR, 3. PARAMETERISED CONSTRUCTOR


// COPY CONSTRUCTOR -> A copy constructor is a member function that initializes an object using another object of the same class
// Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.


// Implicit copy constructor 

class construct
{
    public:
    int m_x;
    int m_y;

    // construct(int x, int y)
    // {
    //     m_x = x;
    //     m_y = y;
    // }

    construct (int x, int y) : m_x(x), m_y(y) {};

    void display()
    {
        std::cout << m_x << "," << m_y << std::endl;
    }
};


int main()
{
    // calling normal constructor
    construct c1(10,20);
    c1.display();

    // call the copy constructor
    construct c2(c1);
    c1.display();

    return 0;
}