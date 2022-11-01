#include<iostream>
using namespace std;
#include<memory> //inorder to use smart pointers


/*
    SMART POINTERS
    Unlike the normal pointers which are not destroyed until it is manually done, they introduced pointers called smart pointers which prevents memory leakage. 
    When the object is destroyed it frees the memory or deallocated the memory. So, we don’t need to delete it as Smart Pointer will handle it. 

    TYPES OF SMART POINTERS:
    1. Unique pointers
    2. Shared Pointers 
    3. Weak pointers

    1. Unique pointers:
        -> It has only one owner. 
        -> unique_ptr stores one pointer only. 
        -> We can assign a different object by removing the current object from the pointer or move the ownership.
        -> BUt when you remove the ownership, your prev owner will point to null
*/

// int main()
// {
//     unique_ptr<int> unq_ptr1 = make_unique<int>(25);
//     // move the ownership
//     unique_ptr<int> unq_ptr2 = move(unq_ptr1);
//     //cout << *unq_ptr1 << endl;  // segmention dump because th unq_ptr1 points to NULL 
//     cout << *unq_ptr2 << endl; // this will be your new owner

// }

class Myclass
{
    public:
    Myclass()
    {
        cout << "Constructor invoked" << endl;
    }
    ~Myclass()
    {
        cout << "Destructor invoked" << endl;
    }

};

int main()
{
    unique_ptr<Myclass>unq_ptr = make_unique<Myclass>();
    unique_ptr<Myclass>unq_ptr2;
    unq_ptr2 = move(unq_ptr);

}
