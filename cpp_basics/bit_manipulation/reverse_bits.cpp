#include <iostream>
using namespace std;

uint32_t reversebits(int n)
{
    uint32_t result = 0;
    for(int i=0; i<32; i++) // assuming its a 32 bit integer 
    {
        result <<= 1; // moving the bits
        result |= (n&1); // copy last bit of n
        n >>= 1; // drop the last bit
    }
    return result;
}



int main()
{
    int n = 11;
    cout << ~n << endl;
    //cout << reversebits(n) << endl;
    return 0;
}