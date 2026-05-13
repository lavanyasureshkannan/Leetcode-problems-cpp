#include <iostream>
#include <cstring>

/*
C++ memcpy() function is a standard library function that is used to copy the specified number of bytes 
from one memory location to another memory location regardless of the type of data stored

memcpy(dst_data, src_data, sizeof(src_data));
//                          ^^^^^^^^^^^^^^^^
//                          1000 * 4 = 4000 bytes
*/

void* memcopy_scratch(void* dest, void* source, size_t size_n)
{
    // here when you just deal with pointers and keep incrementing it,
    // your compiler doesnt know how to increment => cvt to char 
    //Math Check: If you add 1 to an int*, it moves 4 bytes (the size of an int).
    // By casting to unsigned char*, you tell the compiler to move exactly 1 byte at a time
    unsigned char* d = static_cast<unsigned char*> (dest);
    unsigned char* s = static_cast<unsigned char*> (source);
    for(size_t i=0; i<size_n; i++)
    {
        d[i] = s[i];
    }
    return dest;
}

int main()
{
    int a = 10;
    int b = 15;
    memcopy_scratch(&a, &b, sizeof(a));
    std::cout << a << " " << b << std::endl;
    // std::memcpy(&a,&b,sizeof(a));
    // std::cout << a << " " << b << std::endl;

    // int *ptra = &a;
    // int *ptrb = &b;
    // std::memcpy(ptra, ptrb, sizeof(*ptra));
    // std::cout << *ptra << " " << *ptrb << std::endl; 
    return 0;
}