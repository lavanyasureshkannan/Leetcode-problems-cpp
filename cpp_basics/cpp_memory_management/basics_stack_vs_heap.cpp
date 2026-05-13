#include <iostream>
#include <memory>
using namespace std;

/*
    STACK:
    1. Automatic memory (managed by the compiler)
    2. Fast, lifetime is scoped

    HEAP:
    1. Manual you control it
    2. slow and lifetime is till you use delete
*/


int main()
{
    //////////////////// basics //////////////////////////////////
    
    // int x = 10; // stack allocation - global variable
    // {
    //     int y = 12; // stack allocation // local variable
    // }

    // int *p = new int(15); // heap
    // delete p;


    /////////////////////// debugging //////////////////////////////

    // SCENARIO 1

    // int* p;
    // {
    //     int x = 10;
    //     p = &x;
    // }
    // std::cout << *p << std::endl; this case might print 10 but p becomes dangling pointer
    // because the lifetime of the variable x ends inside the scope. 
    // Therefore we are going to use smart pointer
    
    // FIX 
    // std::unique_ptr<int> p = std::make_unique<int>(10);
    
    // SCENARIO 2

    // int* p = new int (10);
    // int* q = p;
    // delete p;
    // cout << *q << endl; // this throws random garbage value.

    // FIX
    unique_ptr<int> p = make_unique<int> (10);
    unique_ptr<int> q = move(p);

    //cout << *p << endl;
    cout << *q << endl;
    
    return 0;
}