#include<iostream>
using namespace std;
/*
        CONST KEYWORD IN POINTERS AND VARIABLES:
        1. const in variable
            -> You cannot left it unassigned
        2. const in pointer (three cases)
            -> const datatype* name -> The pointer pointing to the variable is constant but the values in the variables can be changed.
            -> datatype* const name -> The pointer itself is constant but it can point to any variable and that can be modified
            -> const datatype* name = const dataype -> both are not modifiable.  
        3. const in function or methods
*/

int main()
{
    //1.
    const int a = 10; // right way
    //const int b; // wrong way
    
    //2. 
    // case 1 -> The pointer is pointing to a variable of a specific memory location
                // where the value of the variable can be changed but you cannot make it point to any other variable
    int b = 5;
    const int* b_ptr = &b;
    //cout << b_ptr << " " << *b_ptr << endl; 
    //b = 6;
    //cout << b_ptr << " " << *b_ptr << endl;



    // case 2 -> When the const pointer variable point to the value
    // your pointer is constant and can let it point to anything
    int c = 13;
    int* const c_ptr = &c;
    cout << c_ptr << " " << *c_ptr << endl;
    *c_ptr = 14;
    cout << c_ptr << " " << *c_ptr << endl;



    // case 3 -> when a const pointer pointing to const variable
    //            -> both the constant pointer and variable is not modifyable. 
    const int c_var = 15;
    //const int* c_ptr = &c_var; 



}