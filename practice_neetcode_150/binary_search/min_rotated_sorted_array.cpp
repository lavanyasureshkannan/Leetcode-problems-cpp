#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [3,4,5,6,1,2]
Output: 1
*/

int fin_min_rotated_array_sl1(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    return nums[0];
}

int fin_min_rotated_array_sl2(vector<int>& nums)
{
    return *min_element(nums.begin(), nums.end());
}

int fin_min_rotated_array_sl3(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left  + (right - left) / 2;
        if(nums[mid] < nums[right]) {right = mid;}
        else{left = mid + 1;}
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {3,4,5,6,1,2};
    cout << fin_min_rotated_array_sl1(nums) << endl;
    cout << fin_min_rotated_array_sl2(nums) << endl;
    cout << fin_min_rotated_array_sl3(nums) << endl;
    return 0;
}