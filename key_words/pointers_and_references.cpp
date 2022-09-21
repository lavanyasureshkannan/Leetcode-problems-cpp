// POINTER VS REFERENCE
#include<iostream>
using namespace std;

// PROPERTIES
// 1. You cannot reassign the reference wherease in case of pointer you can reassign
// 2. pointers can be equal to NULL but reference cannot
// 3. Indirections in pointers


int main()
{
    int a = 10; // variable
    int &a_ref = a; // reference
    int *a_ptr = &a; // ptr holds the memory address of a
    int **double_a_ptr = &a_ptr; // indirection
    
    cout << a << endl;
    cout << a_ref << endl;
    cout << *a_ptr << endl;
    
    //this gives you different memory address as output 
    cout << &a << endl;      // address of var a
    cout << &a_ref << endl;  // address of the reference a
    cout << &a_ptr << endl;  // address of the a_ptr 
        
    cout << a_ptr << endl;
    cout << ++(*a_ptr) << endl; // increments the value by 1 which it is pointing to
    cout << ++*(a_ptr) << endl; // increments the value by 1 which it is pointing to
    cout << a_ptr++ << endl; //pointer moves to the next int position (incase of an array)
    cout << ++a_ptr << endl; // pointer moves to the next int position(incase of an array)
    cout << *++(a_ptr) << endl; // moves to next location then use that value
    cout << double_a_ptr << endl;

    return 0;
}