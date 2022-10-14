#include<iostream>
#include<memory>
using namespace std;
/*
    SMART POINTERS
    Unlike the normal pointers which are not destroyed until it is manually done, they introduced pointers called smart pointers which prevents memory leakage. 
    When the object is destroyed it frees the memory or deallocated the memory. So, we don’t need to delete it as Smart Pointer will handle it. 

    TYPES OF SMART POINTERS:
    1. Unique pointers
    2. Shared Pointers 
    3. Weak pointers

    3. Weak pointers
        -> It’s much more similar to shared_ptr except it’ll not maintain a Reference Counter.
        -> In this case, a pointer will not have a stronghold on the object 
        -> after the scope the weak pointer will not keep the memory alive wherease the shared pointer will keep it alive.
*/




class Myclass
{
    public:
    Myclass()
    {
        cout << "contructor is invoked: " << endl;
    }
    ~Myclass()
    {
        cout << "detructor is invoked: " << endl;
    }
};


int main()
{
    weak_ptr<int> wk_ptr1;
    {
        shared_ptr<int> shr_ptr1 = make_shared<int> (25);
        wk_ptr1 = shr_ptr1;
    }
    return 0;
}