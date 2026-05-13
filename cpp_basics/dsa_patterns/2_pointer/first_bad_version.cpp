#include <iostream>
using namespace std;

// Input: n = 5, bad = 4
// Output: 4

bool isBadVersion(int n)
{
    int left = 1;
    int right = n;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(isBadVersion(mid)) right = mid;
        else left = mid + 1;
    }
    return right;
}

// TC: O(log N)
// SC: O(1)


int main()
{
    return 0;
}