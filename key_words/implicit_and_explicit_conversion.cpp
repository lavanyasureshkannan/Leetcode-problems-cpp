#include<iostream>
using namespace std;

/*
    IMPLICIT CONVERSION:
    1. It is also known as automatic conversion.
    2. It is done automatically by the compiler.  
    3. Whenever we are dealing with the expression which deals with multiple data type. During such conditions type conversion takes place in order to avoid lose of data.
    4. ALl the data types of the variable gets upgraded to the largest data type in that expression.

    EXPLICIT CONVERSION:
    1. It is also known as type casting.
    2. It is manually done.
    3. This can be achieved by two ways.
        -> converting by assignment
            (type) expression
        -> conversion by cast operator
            => static cast
            => dynamic cast
            => const cast
            => reinterpret cast
    
    cast operator : A cast operator is an unary operator which forces one data type into another data type.
    1. Static_cast : Its a simple casting in c++ which is used to convert int to float ptr to void* and so on.
    2. Const_cast : It is used to cast away the const of variable. It cannot be applied for a non-cast variables. 
    3. Reinterpret_cast : It is used to convert one pointer data type to another pointer data type.


*/

//In the following example the function recieves normal pointer but a pointer to a const can be passed with the help of const_cast.

int func(int* ptr)
{
    return (*ptr + 10);
}

int main()
{
    // implicit conversion
    // int num = 10;
    // char c = 'a';
    // num = num + c;

    // float z = num + 0.1;

    // cout << num << endl;
    // cout << z << endl;

    // explicit conversion
    
    // => STATIC CAST
    float x = 10.0;
    int y = static_cast<int>(x);
    //cout << y << endl;


    // => CONST CAST'
    // A const_cast can be used to pass const data to a function that doesn't recieve const. 
    // In the following example the function recieves normal pointer but a pointer to a const can be passed with the help of const_cast.
    const int val = 5;
    const int* v_ptr = &val;
    // converting the const int pointer to normal pointer
    int* ptr = const_cast<int *>(v_ptr);
    //cout << func(ptr) << endl;

    // => reinterpret_cast
    // data_type *var_name = reinterpret_cast<data_type *> (pointer_variable)
    int* p_data = new int(65);
    char* ch = reinterpret_cast<char*>(p_data);
    cout << *p_data << " " << p_data << endl;
    cout << *ch << " " << ch << endl; 
    return 0;



}
