#include<iostream>
using namespace std;

// pass by value
// pass by reference
// pass by pointer


// PASS BY REFERENCE -> It allows a function to modify a variable without having to create a copy of it. We have to declare reference variables. 
//                       The memory location of the passed variable and parameter is the same and therefore, any change to the parameter reflects in the variable as well.
int add(int& num1, int& num2)
{
    int result = num1 + num2;
    return result;
}

// PASS BY POINTER
//  the memory location of the variables is passed to the parameters in the function, and then the operations are performed.

void swap(int* a, int* b)
{
    int z = *a;
    *a = *b;
    *b = z;
}


// PASS BY VALUE
int mul(int num1, int num2)
{
    return (num1 * num2);
}

int main()
{
    int x = 9;
    int y = 10;
    cout << add(x,y);

    swap(&x, &y); 
    cout << x << " " << y << endl;

    cout << mul(5,6);
    return 0;
}