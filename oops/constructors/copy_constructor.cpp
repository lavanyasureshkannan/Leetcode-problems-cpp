#include<iostream>

// CONTRUCTOR -> Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
// It is used to initialize the data members of new objects generally.
// Constructor does not have a return value, hence they do not have a return type.
// Three types of constructors
// 1. DEFAULT CONSTRUCTOR, 2. COPY CONSTRUCTOR, 3. PARAMETERISED CONSTRUCTOR


// COPY CONSTRUCTOR -> A copy constructor is a member function that initializes an object using another object of the same class
// Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.

class construct
{
    public:
    int m_x;
    int m_y;
    
    // parameterised contructor
    construct(int x, int y)
    {
        m_x = x;
        m_y = y; 
    }
    // copy constructor
    // ClassName(const ClassName &old_obj)
    construct(const construct& c1)
    {
        m_x = c1.m_x;
        m_y = c1.m_y;
    }
    void display()
    {
        std::cout << m_x << "," << m_y << std::endl; 
    }
};


int main()
{
    // obj1 created and parameerised constructor is called here
    construct c1(5,7);
    c1.display();
    // obj2 is created and the copy constructor is called.  
    construct c2 = c1;
    return 0;
}
