#include <iostream>
#include <map>
using namespace std;

/*
    => hexadecimal is nothing but base 16, means each value can be 0 - 16
     values above 9 will be a - f
    => 
*/

/*
Input: num = 26
Output: "1a"

Input: num = -1
Output: "ffffffff"
*/

string to_hex(int num)
{
    string result;
    string hexa_chars = "0123456789abcdef";
    if(num == 0) return "0";
    unsigned int n = num;
    while(n > 0)
    {
        int remainder = n % 16;
        result = hexa_chars[remainder] + result;
        n = n / 16;
    }
    return result;
}

int main()
{
    int num = -26;
    cout << to_hex(num) << endl;
    return 0;
}