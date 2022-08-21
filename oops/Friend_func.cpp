#include<iostream>
using namespace std;

/*
FRIEND CLASS AND FRIEND FUNCTION
    1. Friend function and class has access to private and protected members in the class
    2. A class can also have multiple friend function
    3. Use friend functions wisely by not breaking the rules of encapsulation
    4. Friendship in classes is not mutual
    5. Friendship is not inherited
*/

// FRIEND FUNCTION 

class Triangle
{
private:
    int a;
    int area;

public:
    void setA(int length)
    {
        a = length;
        area = a*3;
    }

    // specify the friend function
    friend void display(Triangle);
};

void display(Triangle t1)
{
    cout << "Area: " << t1.area << endl;
}


int main() 
{
    Triangle t1;
    t1.setA(5);

    display(t1);
    return 0;
}