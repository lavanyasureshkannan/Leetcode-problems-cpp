#include <iostream>
#include <memory>
using namespace std;

struct test
{
    int a;
    int b;
    // int* ptr; // creates memory leak
    unique_ptr<int> ptr;
};

/*
when a pointer points to a class/struct it creates a contagious block of memory in the heap
with all the variable inside.
*/

void use_val(int& val)
{
    cout << "val " << val << endl;
}

int main()
{
    /********** SCENARIOS WITHOUT POINTERS ********************/
    // unique_ptr<test> test_ptr = make_unique<test>();
    // test_ptr->a = 10; test_ptr->b = 5;
    // cout << test_ptr.get() << endl; 0x5c5c1d93eeb0
    // cout << &(test_ptr->a) << endl; 0x5c5c1d93eeb0
    // cout << &(test_ptr->b) << endl; 0x5c5c1d93eeb4
 
    // unique_ptr<test> test_ptr_2 = move(test_ptr);
    // cout << test_ptr.get() << endl;
    // cout << test_ptr_2.get() << endl; // 0x652e0ae2ceb0
    // cout << &(test_ptr_2->a) << endl; // 0x652e0ae2ceb0
    // cout << &(test_ptr_2->b) << endl; // 0x652e0ae2ceb4

    /*********** SCENARIOS WITH POINTERS *********************/
    // unique_ptr<test> test_ptr = make_unique<test> ();
    // test_ptr->a = 10; test_ptr->b = 20; test_ptr->ptr = new int(10);
    // cout << &(test_ptr->a) << endl;
    // cout << &(test_ptr->b) << endl;
    // cout << test_ptr->ptr << endl;

    // cout << "" << endl;

    // unique_ptr<test> test_ptr_2 = move(test_ptr);
    // cout << &(test_ptr_2->a) << endl;
    // cout << &(test_ptr_2->b) << endl;
    // cout << test_ptr_2->ptr << endl; 

    // here the issue is it creates nested ownership. when test_ptr goes out of scope,
    // now even tho test_ptr is no longer valid, the data it was holding 10 -> was never freed
    // That is exactly why we should use smart pointer instead of raw pointer.
    // THis technique of making sure every every resource has a capability of doing self cleaning 
    // is called RAII (Resource Acquisation Intialization)

    // with fix -> smart pointers

    // unique_ptr<test> test_ptr = make_unique<test> ();
    // test_ptr->a = 10; test_ptr->b = 20; test_ptr->ptr = make_unique<int> (40);
    // cout << &(test_ptr->a) << endl;
    // cout << &(test_ptr->b) << endl;
    // cout << (test_ptr->ptr).get() << endl;

    // cout << endl;

    // unique_ptr<test> test_ptr_2 = move(test_ptr);
    // cout << &(test_ptr_2->a) << endl;
    // cout << &(test_ptr_2->b) << endl;
    // cout << (test_ptr_2->ptr).get() << endl;

    /********** SCENARIOS WHERE YOU PASS UNIQUE POINTERS INSIDE A FUNCTION ******/
    /*
    This is actually the preferred "Modern C++" way if the function doesn't care about the "smartness" of the pointer. 
    Instead of passing the unique_ptr, you just pass a reference to the actual data inside.
    */
    unique_ptr<int> m = make_unique<int> (20);
    use_val(*m);


    return 0;
}