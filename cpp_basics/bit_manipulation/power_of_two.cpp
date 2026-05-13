#include <iostream>
using namespace std;


bool power_of_two(int n)
{
    int count = 0;
    while(n)
    {
        count += (n&1);
        n >>= 1;
    }
    return (count == 1);
}

int main()
{
    cout << power_of_two(8) << endl; // true
    cout << power_of_two(11) << endl; // false
    cout << power_of_two(1) << endl; // true
    return 0;
}