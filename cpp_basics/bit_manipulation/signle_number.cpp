#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Input: nums = [4,1,2,1,2]
    Output: 4

*/

int single_number(vector<int>& nums)
{
    int result = 0;
    for(int i : nums)
    {
        result ^= i;
    } 
    return result;
}

int main()
{
    vector<int> nums = {4,1,2,2,1};
    cout << single_number(nums) << endl;
    return 0;
}