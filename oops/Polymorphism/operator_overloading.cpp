#include<iostream>
using namespace std;

/*
    POLYMORPHISM -> simple means exists in more than one form. 
    The entity behaves differently at different scenarios
    
    Two types of polymorphism -> Compile time polymoriphism, Run time polymorphism  
    There are three ways you can achieve polymorphism
    
    COMPILE TIME 
    1. FUnction Overloading
    2. Operator Overloading

    RUNTIME 
    1. Function Overriding
    2. Virtual Functions 
*/

/*
Operator Overloading -> we can change the way operators work for user-defined types like objects and structures. This is known as operator overloading.
Default overloading operators in c++ : = , &
Operators that cannot be overloaded in c++ are --> ::(scope resolution), .(member selection), .*(member selection through pointer to function), ?.(ternary operations)
*/

int add_to_numbers(int num1, int num2)
{
    int total = num1 + num2;
    cout << total << endl;
    return total;
}

string add_two_strings(string a, string b)
{
    string result = a+b;
    cout << result << endl;
    return result;
}

int main()
{
    // same operator performs differently between two intgers and the string
    add_to_numbers(5,10);
    add_two_strings("aa","bb");
    return 0;
}



