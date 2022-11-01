// FUNCTORS or function pointers
// tip: "auto" ->   keyword is used in function pointers 
// Functors are objects that can be treated as though they are a function or function pointer.
// A function pointer is a variable that stores the address of a function that can later be called through that function pointer. 
// This is useful because functions encapsulate behavior.




#include<iostream>
using namespace std;

// without param
int getNum()
{
    return 5;
}

// with param
int add(int a, int b)
{
    return a+b;
}


int main()
{
    // function pointer which is pointing to the function
    int(*func_ptr)() = getNum;
    cout << func_ptr() << endl;
    // with param
    int(*func_ptr_2)(int, int) = add;
    cout << add(2,3) << endl;
    cout << add(4,5) << endl;
    return 0;
}
