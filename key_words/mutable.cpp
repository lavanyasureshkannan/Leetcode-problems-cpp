#include<iostream>
#include<vector>
using namespace std;

/*
    MUTABLE: Something that can be changed.
    It is something that can violate the rule of const at times.
    IMMUTABLE : Something that cannot be changed

*/
class base
{
    public:
    int x;
    mutable int y;
    base()
    {
        x = 4;
        y = 10;
    }
};


int main()
{
    const base b1;
    b1.y = 15;
    cout << b1.x << " " << b1.y;
    return 0;
}