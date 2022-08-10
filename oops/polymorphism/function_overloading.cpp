#include<iostream>
using namespace std;

/*
    POLYMORPHISM -> simple means exists in more than one form. 
    The entity behaves differently at different scenarios
    
    There are three ways you can achieve polymorphism
    1. FUnction Overloading
    2. Operator Overloading
    3. Function Overriding
    4. Virtual Functions 
*/

/*


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