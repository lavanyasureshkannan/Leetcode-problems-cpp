#include<iostream>
using namespace std;
/*
    INLINE FUNCTION : When a function is declared with the inline keyword, then when it is actually called the declaration gets substituted. 
    This reduces the execution time and it is less than the switching time from the caller functio to called. 

    Note: Inline is a request to the compiler not a command. compiler can ignore the request for inlining under certain circumatances like
    if the function has loops.
    if the function has any recurrsion function
    if it has static variables
    if it has switch statements

    Advantages:
    1. Function call overhead doesn’t occur.
    2. It also saves the overhead of push/pop variables on the stack when function is called.
    3. saves time.

    Disadvantages
    1. Inline functions may not be useful for many embedded systems
    2. Inline functions might cause thrashing because inlining might increase size of the binary executable file. 
        Thrashing in memory causes performance of computer to degrade.
    3. If you use too many inline functions then the size of the binary executable file will be large, 
        because of the duplication of same code.
*/

inline void display(string str)
{
    cout << str << endl;
}

int main()
{
    for(int i = 0; i < 1000; i++)
    {
        display("hello world");
    }
    return 0;
}