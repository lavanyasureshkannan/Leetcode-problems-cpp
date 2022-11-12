#include<iostream>
using namespace std;

/*  
    Void: 
    1. Void is a function which has no return type and can be executed without the parameters.
    2. The size of void depends on the compiler. 
        We can use sizeof command to represent the void function in the gcc compiler and the answer will be 1.
        But incase of other compilers we get an error. 

    Void pointer:
    1. Void pointer can hold the memory any type of variable.
    2. It is also called as universal pointer
    3. Void cannot be dereferenced.
    4. We can convert any data type pointer into void pointer(except function pointer, const and volatile).
    5. we can pass in the void pointer as an argument.

    // In one line : void means nothing, void pointer means pointing to anything

    // use cases:
    malloc and calloc return void pointer so that we can typecast to our desired data type
*/


int main()
{
    int a = 10;
    
    // int* ptr_a = &a; // declaring the pointer with data type
    //void* ptr = &a; 
    //cout << ptr << endl; 
    //cout << *ptr <<  endl;    //compilation error 
    
    // deference the void pointer in order to get the value
    //cout << *(int *)ptr << endl;

    cout << display_data(&a,'c');
    return 0;
}