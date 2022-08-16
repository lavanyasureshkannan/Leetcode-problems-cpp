#include<iostream>

// CONTRUCTOR -> Constructor in C++ is a special method that is invoked automatically at the time of object creation. 
// It is used to initialize the data members of new objects generally.
// Constructor does not have a return value, hence they do not have a return type.
// Three types of constructors
// 1. DEFAULT CONSTRUCTOR, 2. COPY CONSTRUCTOR, 3. PARAMETERISED CONSTRUCTOR


// PARAMETERISED CONSTRUCTOR
class construct
{
    private:
    int x,y;

    public:
    construct(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void display()
    {
        std::cout << x << "," << y << std::endl;
    }

};

int main()
{
    // create object from the class
    construct c1(100, 200);
    c1.display();
    return 0;
}