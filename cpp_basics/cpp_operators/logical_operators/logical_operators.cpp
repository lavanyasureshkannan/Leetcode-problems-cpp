#include <iostream>
using namespace std;

/*

    LOGICAL OPERATORS

    In terms of numbers they check zeros vs non zeros
    && => check if both the values are true. non-zero - true, zero - false
    || => check if either of the values are true or non zero
    ! => check if the operand is true or false

*/

bool evaluate_logical_and()
{
    // int x = 10; (both are non zero)
    // int y = 8;

    int x = 6;
    int y = 0;

    return (x && y);
}

bool evaluate_logical_or()
{
    // int x = 0;
    // int y = 4;

    int x = 0;
    int y = 0;
    return (x || y);
}

bool evaluate_logical_not()
{
    //int a = 0;
    // int a = 1;
    int a = -2;
    return (!a);
}

int main()
{
    //cout << evaluate_logical_and() << endl;
    //cout << evaluate_logical_or() << endl;
    cout << evaluate_logical_not() << endl;
    return 0;
}