#include <iostream>
using namespace std;
/*

    & => compare two bits. returns 1 only when both bits are 1. rest all 0.
    | => compare two bits. return 1 when either one of the bits are 1. two bits are 0 ends in 0.
    ^ => compare two bits. return 0 when two bits are 11 and 00. rest all 1. 
    << => left shift. Interms of bits it shifts the last bit towards left.
    >> => right shift. Interms of bits it shifts the first bit towards right.
*/ 



bool bitwise_and_check()
{
    int x = 7; // 0111
    int y = 8; // 1000
    int result = x & y; // 0000
    return result;
}

bool bitwise_or_check()
{
    int x = 7; // 0111
    int y = 8; // 1000
    int result = x | y; // 1111
    return result;
}

bool bitwise_xor_check()
{
    int x = 7; // 0111
    int y = 8; // 1000
    int result = x ^ y; // 1111
    return result;
}

int left_shift_bits()
{
    int x = 19; // 11001 (divide 19 by 2 and take all the remainders)
    // int is 32 the bit representation looks like 
    // 00000000 00000000 00000000 00010011
    return x << 1; // 00000000 00000000 00000000 00100110
}

int right_shift_bits()
{
    int x = 19; // 11001
    return x >> 1; // 00000000 00000000 00000000 00001001
}

int main()
{
    cout << bitwise_and_check() << endl;
    cout << bitwise_or_check() << endl;
    cout << bitwise_xor_check() << endl;
    cout << left_shift_bits() << endl; // converts back to decimal
    cout << right_shift_bits() << endl; // converts back to decimal

    return 0;
}