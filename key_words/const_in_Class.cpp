#include<iostream>
using namespace std;

class base
{
    private:
    int m_x;
    int m_y;

    // the actual values of m_x cannot be changed and its gonna be read only
    int getX() const 
    {
        return m_x;
    }
};

// when an object is constant then it can call only const member functions
// constructors and destructors can never be const


int main()
{
    return 0;
}
