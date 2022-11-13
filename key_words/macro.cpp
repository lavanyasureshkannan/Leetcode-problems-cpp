#include<iostream>
using namespace std;

/*
    MACRO
    A macro is a piece of code in a program that is replaced by the value of the macro. 
    Macro is defined by #define directive. 
    Whenever a macro name is encountered by the compiler, it replaces the name with the definition of the macro
*/

#define N 5+2 // irrespective of the function it gets directly substituted.

int main()
{
    cout << N*2 << endl;
}
