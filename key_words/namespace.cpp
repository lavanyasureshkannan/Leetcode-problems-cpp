#include<iostream>

/*
    NAMESPACE
    -> The primary purpose of the namespace is to avoid naming conflicts
    -> There are different libraries which has the same names. Inorder to avoid such conflicts we use namespace


*/

// creating our own namespace

namespace utils
{
    int add(int a, int b)
    {
        return (a+b);
    }
}

int main()
{
    std::cout << utils::add(2,3) << std::endl;
    return 0;
}
