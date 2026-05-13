#include <iostream>
using namespace std;

int guessnumber(int n)
{
    int left = 0;
    int right = n;
    while(left < right)
    {
        int mid = left + (right - left)/2;
        int result = guess(n);
        if(result == mid) return mid;
        if(result < 0) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    return 1;
}

int main()
{
    return 0;
}