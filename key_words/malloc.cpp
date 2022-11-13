#include<iostream>
using namespace std;
/*
    MALLOC Keyword
    1. Malloc is a function used to allocate the requested size of bytes and returns the pointer to the first byte.
    2. Malloc is a function.
    3. syntax,
        datatype* pointer_name = (cast type*)malloc(sizeof(int));
    4. Variables or Arrays created using malloc exist for a lifetime until they are cleared.
    5. returns a void pointer or null pointer

*/

int main()
{
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 6; 
    cout << *ptr << endl;
    return 0;
}
