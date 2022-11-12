#include<iostream>
using namespace std;

/*
    Const exp is a keyword that can be added infront of the function which represents that the performance of the function can be improvised in compile time rather than run time.
    The main idea is to spend time in compile time and save time in run time. 
    In C++ 11, a constexpr function should contain only one return statement. C++ 14 allows more than one statement.
    constexpr function should refer only to constant global variables.
*/


/*
    Constexp vs Inline
***********************************************************|**********************************************************************************************************|
    Constexpr                                              |             Inline Functions                                                                             |
***********************************************************|**********************************************************************************************************|
 1. It removes the function calls as it evaluates          |         It hardly removes any function call as it performs an action on expression in the run time.      |
    the code/expressions in compile time.	               |                                                                                                          | 
 **********************************************************|**********************************************************************************************************|
 2. It is possible to assess the value of the variable or  |         It is not possible to assess  the value of the function or variable at compile time.             |
    function at compile time.                              |                                                                                                          |
***********************************************************|**********************************************************************************************************|
 3. It does not imply external linkage.	                   |        It implies external linkage.                                                                      |
***********************************************************|**********************************************************************************************************|
*/
constexpr int add(int a, int b)
{
    return (a+b);
}

int main()
{
    constexpr int result = add(10,20);
    cout << result << endl;
    return 0;
}