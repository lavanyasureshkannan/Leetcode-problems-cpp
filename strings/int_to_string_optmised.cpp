#include <iostream>
#include <vector>
using namespace std;

string itoa(int num)
{
    // base case
    if(num == 0) return "0";
    // 1. fixed buffer of max length
    vector<char> buffer(12);
    // 2. start from the end
    char *ptr = buffer.data() + buffer.size();
    // 3. Null terminator
    *--ptr = '\0';
    // 4. convert the negative to positive
    bool isnegative = num < 0;
    if(isnegative)
    {
        // convert int to unsigned int to avoid overflow
        num = static_cast<unsigned>(-(num));
    }
    else 
    {
        num = static_cast<unsigned>(num);
    }
    // 5. extract the digit backwards
    while(num != 0)
    {
        int digit = num % 10;
        *--ptr = digit + '0';
        num = num / 10;
    }
    if(isnegative)
    {
        *--ptr = '-';
    }
    // 6. return the string
    return string(ptr);
}


int main()
{
    cout << itoa(0);
    // cout << INT_MAX << endl;
    // cout << INT_MIN << endl;
}


