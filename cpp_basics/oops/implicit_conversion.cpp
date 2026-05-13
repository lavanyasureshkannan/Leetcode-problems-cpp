#include <iostream>
using namespace std;

/*
IMPLICIT CONVERSION -> Its like a bug that happens when we are dealing with one param in the constructor.
*/

class Number
{
    public:
    int n;
    Number(int m_n)
    {
        n = m_n;
    }
};
void display(Number n)
{
    cout << n.n << endl;
}

int main()
{
    Number n1 = 5; // this assumes that the param inside the constructor value is 5 => Number n1(5)
    display(10);
    return 0;
}