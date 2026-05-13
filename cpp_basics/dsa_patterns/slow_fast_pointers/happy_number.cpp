#include <iostream>
using namespace std;

/*
Input: n = 19
Output: true
*/

int calculate_sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        int digit = n % 10; 
        sum += (digit * digit);
        n = n/10; 
    }
    return sum;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = calculate_sum(n);
    while(fast != 1 && slow != fast)
    {
        slow = calculate_sum(slow);
        fast = calculate_sum(calculate_sum(fast));
    }
    return fast == 1;
}

int main()
{
    cout << isHappy(19) << endl;
    return 0;
}