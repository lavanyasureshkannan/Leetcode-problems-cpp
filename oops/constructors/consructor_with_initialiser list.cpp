#include<iostream>

// CONTRUCTOR -> Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
// It is used to initialize the data members of new objects generally.
// Constructor does not have a return value, hence they do not have a return type.
// Three types of constructors
// 1. DEFAULT CONSTRUCTOR, 2. COPY CONSTRUCTOR, 3. PARAMETERISED CONSTRUCTOR


// PARAMETERISED CONSTRUCTOR with INITIALIZER LIST -> much preferred due to the peformance
class construct
{
    public:
    int x,y;

    public:
    construct() : x(0), y(0) 
    {

    }
    construct(int x1, int y1) : x(x1),y(y1)
    {
        
    } 
    void display()
    {
        std::cout << x << "," << y << std::endl;
    }

};

int main()
{
    construct c1;
    c1.display();

    construct c2(5,6);
    c2.display();

    return 0;
}