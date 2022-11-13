#include<iostream>
using namespace std;
/*
        CONST KEYWORD IN POINTERS AND VARIABLES:
        1. const in variable
            -> You cannot left it unassigned
        2. const in pointer (three cases)
            -> const datatype* name -> The pointer pointing to the variable is constant but the values in the variables can be changed.
            -> datatype* const name -> The pointer itself is constant but it can point to any variable and that can be modified
            -> const datatype* name = const dataype -> both are not modifiable.  
        3. const in function
            -> Const return type
            -> const return type with const params
        4. const in class member function
*/

// 3. 
// case 1: const return type
const int nums(int x)
{
    x--;
    cout << x << endl;
    return x;
} 

// case 2: const return type with the const param
const int add(const int a, const int b)
{
    cout << a+b << endl;
    return a+b;
}


int main()
{
    const int a = 10;
    const int b = 15;
    add(a,b);
    nums(10);
    return 0;
}