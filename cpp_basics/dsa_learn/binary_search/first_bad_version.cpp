#include <iostream>
using namespace std;

int first_bad_version(int n)
{
    int left = 1;
    int right = n;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(isBadversion[mid])
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }
    return right;
}


int main()
{
    return 0;
}