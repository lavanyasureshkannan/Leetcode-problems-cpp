#include<iostream>
using namespace std;

/*
    shallow copy -> We are just making the copy of every variable and data inside the class. 
    If the memory is allocated on the heap then you will return a pointer. When you create a copy of a pointer both points to the same memory location.
    So changes made in one will affect the other.
    This will cause run time errors.
*/


class rectangle
{
    int m_height;
    int m_width;
    public:
    rectangle(int height, int width)
    {
        m_height = height;
        m_width = width;
    }
    void display()
    {
        cout << m_height << " " << m_width << endl;
    }
};


int main()
{
    rectangle r1(10,20);
    r1.display();
    rectangle r2 = r1;
    r2.display();
    rectangle r3 = r1;
    r3.display();

    return 0;
}