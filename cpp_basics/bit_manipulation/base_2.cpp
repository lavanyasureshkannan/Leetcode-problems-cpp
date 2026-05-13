#include <iostream>
using namespace std;

string base_2(int num)
{
    if(num == 0) return "0";
    bool isnegative = false;
    string result;
    if(num < 0)
    {
        isnegative = true;
        num = -(num);
    }
    while(num > 0)
    {
        int remainder = num % 2;
        result = to_string(remainder) + result;
        num = num / 2;
    }
    if(isnegative)
    {
        result = "-" + result;
    }
    return result;
}

int main()
{
    int num = -100;
    cout << base_2(num) << endl;
    return 0;
}