#include<iostream>
using namespace std;

/*
TYPE PUNNING: It is a process of converting one data type into other in the same memory space.
A form of pointer aliasing where two pointers and refer to the same location in memory but represent that location as different types. 
Get the type as the pointer and then cast it to different pointer and then dereference it.

*/

int main()
{
    // In the following code a will have different memory address and b will have different memory address
    int a = 10;
    //double b = a;
    //cout << &a << " " << &b << endl;

    // we want to make both the memory address same
    //double b = *(double*) &a;
    //cout << &a << " " << &b << endl; // again this is the bad way to do it.
    int* p = (int*)&a;
    int b = *(int*)((char*)&a); 
    cout << b << endl;


    return 0;
}