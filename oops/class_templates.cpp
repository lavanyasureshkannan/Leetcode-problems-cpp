#include<iostream>
using namespace std;

/*
    TEMPLATES
    1. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types
*/

// CLASS TEMPLATE

template<class T>

class Number
{
    public:
    T m_a;

    Number(T a) : m_a(a) {};

    void display()
    {
        cout << "The num is : " << m_a << endl;
    }
};

int main()
{
    // create an object using int type
    Number<int> number_int(5);
    number_int.display();

    // create an object using float
    Number<float> number_float(10.3);
    number_float.display();
    return 0;
}