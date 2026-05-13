#include <iostream>
#include <vector>
using namespace std;


/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

vector<int> sort_colors(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() -1;
    int mid = 0;

    while(left < right && mid <= right)
    {
        if(nums[mid] == 0)
        {
            swap(nums[left], nums[mid]);
            left++;
            mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[right]);
            right --;
        }
    }
    return nums;
}

// TC: O(log N)
// SC: O(1)

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    vector<int> result = sort_colors(nums);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}