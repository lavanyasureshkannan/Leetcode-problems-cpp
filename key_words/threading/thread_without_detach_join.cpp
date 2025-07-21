#include <iostream>
#include <thread>
using namespace std;

void func1()
{
    cout << "thread func 1" << endl;
}

void func2()
{
    cout << "thread func 2" << endl;
}

int main()
{
    thread t1(func1);
    thread t2(func2);
    return 0;
}

//O/P : terminate called without an active exception