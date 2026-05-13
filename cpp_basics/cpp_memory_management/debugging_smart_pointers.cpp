#include <iostream>
#include <memory>
using namespace std;

void print(unique_ptr<int>& ptr)
{
    if(ptr)
    {
        cout << *ptr << endl;
    }
}

int main()
{
    unique_ptr<int> a = make_unique<int>(12);
    print(a);
    return 0;
}