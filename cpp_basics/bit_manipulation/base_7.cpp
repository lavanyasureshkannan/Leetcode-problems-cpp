#include <iostream>
#include <string>
using namespace std;

/*
Input: num = 100
Output: "202"
*/

string convert_base7(int num)
{
    string result = "";
    // num = 0
    if(num == 0) return "0";

    // num -ve
    bool isnegative = false;
    if(num < 0) 
    {
        isnegative = true;
        num = -(num);
    }

    // num +ve
    while(num > 0)
    {
        int remainder = num % 7;
        result = to_string(remainder) + result;
        num = num / 7;
    }

    if(isnegative)
    {
        result = "-" + result;
    }
    return result;
}


int main()
{
    int num = -7;
    cout << convert_base7(num) << endl;
    return 0;
}