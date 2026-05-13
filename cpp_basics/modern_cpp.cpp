#include <iostream>
using namespace std;

template<typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
}

int main()
{
    string name = "lavanya";
    int age = 27;
    Log("Name: ", name, " Age: ", age);
    return 0;
}