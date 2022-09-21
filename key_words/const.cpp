#include<iostream>
using namespace std;

// Whenever const keyword is attached with any method(), variable, pointer variable, and with the object of a class it prevents that specific object/method()/variable to modify its data items value.
// 1. Constant Variables
// 2. Const Keyword With Pointer Variables
//      When the pointer variable point to a const value
//      When the const pointer variable point to the value
//      When const pointer pointing to a const variable
//      Pass const-argument value to a non-const parameter of a function cause error
// 3. Constant Methods
// 4. Constant Function Parameters And Return Type
//      For const return type
//      For const return type and const parameter


// PROPERTIES OF CONST
// 1. const variable needs to be declared.
// 2. "const data_type* name_of_the_pointer" => When a pointer is pointing towards that const variable -> the value of the variable cannot be changed. 
// 3. "data_type* const name_of_the_pointer" => When you want to change the variable that has a pointer pointing towards its memory address
// 4. "const int* const z" => when a const pointer pointing towards const variable => So, you are neither allowed to change the const pointer variable(*P) nor the value stored at the location pointed by that pointer variable(*P).
// 5. Passing const argument value to a non-const parameter of a function isn’t valid it gives you a compile-time error.
// 6. Like member functions and member function argument object can also be declared as const.
//          When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
//          Whenever an object is declared as const, it needs to be initialized at the time of declaration 
// 7. Const member function as class


#include<iostream>
using namespace std;

void num1(int xx)
{
    cout << xx << endl;
}

void num2(const int y)
{
    cout << y << endl;
}

const int num3(const int z)
{
    return z;
}
int main()
{
    // 1. const variable needs to be declared.
    const int x = 10;


    // 2. When a pointer is pointing towards that const variable -> the value of the variable cannot be changed. 
    const int a = 5;
    const int* a_ptr = &a;

    // 3. when you want to change the variable that has a pointer pointing towards its memory address
    int y = 16;
    int* const y_ptr = &y;  // the const pointer y_ptr pointing towards the memory loation of y
    *y_ptr = 17; // cout << y << " " << *y_ptr << endl => 17,17

    // 4. when a const pointer pointing towards const variable => So, you are neither allowed to change the const pointer variable(*P) nor the value stored at the location pointed by that pointer variable(*P).
    const int z = 10;
    const int* z_ptr = &z;

    num1(55);
    num2(z);
    cout << num3(56);
    return 0;
}
