#include<iostream>
using namespace std;
/*
    NEW KEYWORD
    - You will use new keyword to allocate memory on the heap
    - New keyword tries to find a block memory.
    - Once the memory has been allocated it return the pointer that point towards the memory.
    - New is just an operator and it can be overloaded
    - When you create an object using new keyword it also calls the constructor
    - When you use new keyword you must use delete.
*/

class base
{
    public:
    void display()
    {
        cout << "inside base class" << endl;
    }
};

int main()
{
    int a = 2;
    int* b = new int;
    int* arr = new int[50];
    base* b1 = new base(); // allocates memory and calls the constructor

    delete b;
    delete[] arr; 
    delete b1; // It also calls the destructor


}