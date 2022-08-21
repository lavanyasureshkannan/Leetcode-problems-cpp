#include<iostream>
using namespace std;

/*
    TEMPLATES
    1. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types
*/

// FUNCTION TEMPLATE

template<typename T>

T add(T num1, T num2)
{
    cout << (num1+num2) << endl;
    return (num1+num2);
}



int main()
{
    add(5,6);
    add(5.5,6.6);
    return 0;
}