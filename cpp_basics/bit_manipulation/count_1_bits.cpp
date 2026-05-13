#include <iostream>
using namespace std;

/*
    input-> n = 11 -> binary 1011
    output-> 3

*/

// int count_1s_bits(int n)
// {
//     int count = 0;
//     while(n)
//     {
//         count += (n&1);
//         n >>= 1;
//     }
//     return count;
// }

int number_of_bits(int n)
{
    int count = 0;
    while(n)
    {
        if(n&1) // check if the last bit is 1
        {
            count ++;
        }
        n >>= 1;
    }
    return count;
}

// int count_bits(int n)
// {
//     int count = 0;
//     while(n)
//     {   
//         count += n&1;
//         n >>= 1;
//     }
//     return count;
// }



int main()
{
    //cout << count_bits(11) << endl;
    cout << number_of_bits(11) << endl;
    return 0;
}