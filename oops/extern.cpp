#include<iostream>
using namespace std;

/*
    Extern keyword
    The extern keyword will tell the compiler that the variable has been declared somewhere else outside the translation unit. 
    So the linker tries to find this actual declaration and sets up the extern variable to point to the correct location.
*/

int main()
{
    extern int i = 5;
    cout << i; // will give you compile time error
    return 0;
}
