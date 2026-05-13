#include <iostream>
using namespace std;

/*
    Input = 16;
    output = 4;

    logic:
    1. Ignore 0,1
    2. start from 2 and the first half of the input
    3. find the pivot and increase left and right accordingly
*/

int sq_root(int num)
{
    // base case
    if(num < 2)
    {
        return num;
    }
    int left = 2;
    int right = num/2;
    long square_num;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        square_num = mid * mid;
        if(square_num > num) 
        {
            right = mid - 1;
        }
        else if (square_num < num)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
        
    }
    return right;
}

int main()
{
    int num = 8;
    cout << sq_root(num);
    return 0;
}