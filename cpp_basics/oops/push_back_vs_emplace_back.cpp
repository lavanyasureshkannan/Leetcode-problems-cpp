#include <iostream>
#include <vector>
using namespace std;

class myclass
{
    public:
    int x;

    myclass(int m_x)
    {
        x = m_x;
    }
};

int main()
{
    vector<myclass> vec;
    myclass obj1(3);
    vec.push_back(obj1);


    vector<myclass> vec2;
    vec2.emplace_back(10);
    return 0;
}