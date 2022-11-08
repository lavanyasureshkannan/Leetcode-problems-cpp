#include<iostream>
using namespace std;

// When a variable is declared as static, space for it gets allocated for the lifetime of the program.
// accessing STATIC VARIABLE and STATIC FUNCTIONS INSIDE THE CLASS.

class base
{
    public:
    base() {}
    static int num1;
    static int num2;

    int i;
    static int return_num(int i)
    {
        return i;
    }
    static int add(int num1, int num2)
    {
        return num1 + num2;
    }
};

// datatype classname :: static variable
int base :: num1 = 3;
int base :: num2 = 4;  

// You cannot access the non-static member variable outside the class (like below). 
// int base :: i = 10;


int main()
{
    base b1;
    cout << b1.num1 << " " << b1.num2 << endl;
    cout << b1.add(b1.num1, b1.num2) << endl;

    cout << base::add(6,7) << endl;
    return 0;
}