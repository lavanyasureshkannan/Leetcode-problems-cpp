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

    2. Shared Pointers
        -> It has more than one owner
        -> By using shared_ptr more than one pointer can point to this one object at a time
        -> It’ll maintain a Reference Counter using use_count() method. 
        -> Every single owner will be destroyed at the end of its scope.
        -> The memory location will be deallocated only if pointers pointing to the owner
*/


class Myclass
{
    public:
    Myclass()
    {
        cout << " CONSTRUCTOR IS INVOKED" << endl;
    }
    ~Myclass()
    {
        cout << " DESTRUCTOR IS INVOKED" << endl;
    }
};

int main()
{
    shared_ptr<Myclass>shr_ptr1 = make_shared<Myclass>(); // one owner
    // you can keep track of the owners by .useCount()
    cout << "Number of shared count: " << shr_ptr1.use_count() << endl;
    // lets say we have one more owner
    shared_ptr<Myclass>shr_ptr2 =  shr_ptr1; // second owner to the same memory location
    cout << "Number of shared count: " << shr_ptr2.use_count() << endl;
    return 0;
}
