#include <iostream>
#include <algorithm>
using namespace std;


string itoa(int num)
{
    // base condition
    if(num == 0) return "0";

    // if it is a negative number
    bool isNegative = false;
    if(num < 0)
    {
        isNegative = true;
        num = -(num);
    }
    // if its postive number
    string result = " ";
    while(num > 0)
    {
        int digit = num % 10; // remainder keep addding this in the result
        result  += (digit + '0');
        num = num / 10; // this to check if the loop should continue or not
    }
    if(isNegative)
    {
        result = result + "-";
    }

    reverse(result.begin(), result.end());
    cout << result;
    return result;


}


int main()
{
    int a = -123;
    itoa(a);
    return 0;
}