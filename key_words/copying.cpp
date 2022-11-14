#include<iostream>
#include<vector>
using namespace std;

/*
    COPYING 
    1. If you copy a variable to another variable it will occupy two different memory.
    2. Similarly incase of pointer, you are actually copying the memory address of the pointer.
    3. If the variables are allocated in the heap then it means both the pointer points to the same memory location.

*/

struct vector2
{
    int x; 
    int y;
};

int main()
{
    int a = 10;
    int b = a;
    //cout << &a << " " << &b << endl; // the memory address will be different

    vector2 v1;
    v1.x = 3;
    v1.y = 4;

    vector2 v2 = v1;
    v2.x = 5;
    v2.y = 6;

    cout << v1.x << " " << v1.y << " " << v2.x << " " << v2.y; 

    // now here they are two pointers pointing to the same thing
    vector2* v3 = new vector2();
    vector2* v4 = v3;
    v3->x = 10; // it affects both v4, v3

    return 0;
   
}