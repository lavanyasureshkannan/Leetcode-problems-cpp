#include <iostream>
using namespace std;

/*
    Global varibale => Accessed from anywhere inside the program. It gets destroyed at the end of the program.
    stack / Local variable => Accessed inside the func and destroyed once the func goes out of scope.
    Static variable => Accessed and modified throughout the translational unit.
    Heap variable => Allocated in runtime. Lifetime is controlled by the programmmer. Use new and delete.

*/


int global_variable = 10;

void func()
{
    cout << "GLobal variable: " << global_variable << endl;
    int local_variable = 5;
    cout << "Local variable: " << local_variable << endl;
    int* heap_variable = new int(3);
    cout << "Heap variable: " << *heap_variable << endl; 
    delete heap_variable;
    cout << *heap_variable << endl; // prints garbage because nothing eixts there
}

static int static_Variable = 1;
void counter()
{
    static_Variable ++;
    cout << "static variable: " << static_Variable << endl;
}

void counter2()
{
    static int static_variable_func = 1;
    static_variable_func ++;
    cout << "static variable func: " << static_variable_func << endl;

}

void arr_func_stack()
{
    int arr[5] = {10,20,30,40,50}; // stack storage
    // numbers inside the array will be stored continously
    for(int i=0; i<5; i++)
    {
        cout << &arr[i] << endl;
    }
}

void arr_func_heap()
{
    int* arr = new int[5] {10,20,30,40,50};
    for(int i=0; i<5; i++)
    {
        cout << &arr[i] << endl; 
    }
    delete[] arr;   
}


int main()
{
    //func();
    
    //cout << "///////////////////////////////////////////////////////////" << endl;
    //counter();
    // counter();
    // counter();
    
    //cout << "///////////////////////////////////////////////////////////" << endl;
    // counter2();
    // counter2();
    // counter2();

    arr_func_stack();
    cout << "///////////////////////////////////////////////////////////" << endl;
    arr_func_heap();
    return 0;
}