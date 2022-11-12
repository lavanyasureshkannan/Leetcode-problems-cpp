#include<iostream>
using namespace std;

/*
    // function pointers
    // tip: "auto" ->   keyword is used in function pointers 
    // A function pointer is a variable that stores the address of a function that can later be called through that function pointer. 
    // This is useful because functions encapsulate behavior.
*/

// 1. with param 
int get_num()
{
    return 5;
}

// 2. without param
int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

// 3. pass function pointer as an argument to another function

int my_func(int(*ptr_add)(int,int)) // passing the address of add(&add)
{
    int result = ptr_add(3,4);
    return result;
}


// 4. How will you return a function pointer
// you can use typedef
typedef int(*my_func_ptr)(int,int);

my_func_ptr fun_math (int num)
{
    if(num == 1)
        return add;
    else
        return sub;
} 

int main()
{
    // datatype(* name_ptr)(datatype of param)
    // 1.
    int(*func_ptr)() = get_num;
    //cout << func_ptr() << endl;

    // 2.
    int(*func_ptr_2)(int,int) = add;
    //cout << func_ptr_2(5,6) << endl;

    // 3.
    //int return_my_func = my_func(add) << endl;
    //cout << return_my_func;

    // 4.
    int(*ptr_a)(int,int);
    ptr_a = my_func_ptr(1);
    int n = ptr_a(2,3);
    cout << n;

}
