#include <iostream>

using namespace std;



#include <iostream>
using namespace std;

/*
Explicit CONVERSION -> Its to avoid the bug that happens when we are dealing with one param in the constructor/implicit conversions.
*/

class Number
{
    public:
    int n;
    explicit Number(int m_n)
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
    Number n1(5); // this assumes that the param inside the constructor value is 5 => Number n1(5)
    display(Number(10));
    return 0;
}
