#include<iostream>

/* NAMESPACE -> you will use this when you have two variables declared with the same name
    using namespace std is not recommended as std :: import all the libraries
*/

namespace namespace1
{
    void display()
    {
        std::cout << "displayed" << std::endl;
    }
    int var = 25;
}

namespace namespace2
{
    int var = 70;
}


int main()
{
    namespace1::display();
    return 0;
}