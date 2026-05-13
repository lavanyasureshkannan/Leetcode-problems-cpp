#include <iostream>
using namespace std;

/*
    1. PRINT NUMBERS FROM 1-5
*/

void print_numbers(int n)
{
    // base case
    if(n == 0) return;
    // recurssive call
    cout << n << endl;
    print_numbers(n-1);
}

/*
    2. PRINT SUM OF NUMBERS
*/
int sum_of_numbers(int n)
{
    // base case
    if(n == 0) return -1;
    return (n + sum_of_numbers(n-1));
}

/*
    3. FACTORIAL
*/
int factorial (int n)
{
    // base case
    if(n == 1) return 1;
    return (n * factorial(n-1));
}

int main()
{
   // print_numbers(5);
    cout << sum_of_numbers(4) << endl;
    cout << factorial(4) << endl;
    return 0;
}