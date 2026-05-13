#include<iostream>
using namespace std;

/*
    POLYMORPHISM -> simple means exists in more than one form. 
    The entity behaves differently at different scenarios
    
    There are Two types of polymorphism
    1. COMPILE TIME                       2. RUNTIME
        ->FUnction Overloading              -> Function Overriding
        ->Operator Overloading              -> Virtual Functions   

*/

/*

FUnction Overloading -> Two functions can have the same name if the number and/or type of arguments passed is different.

*/


int sum(int num1, int num2)
{   
    int total = num1 + num2;
    cout << total << endl;
    return total;
}

double sum(double num1, double num2)
{
    int total = num1+ num2;
    cout << total << endl;
    return total;
}

int main()
{
    sum(5,6); // calls the first function
    sum(5.2,6.5); //calls the second function
    return 0;
}