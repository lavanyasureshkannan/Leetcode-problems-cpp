#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

void display(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
void sortcolors(vector<int>& nums)
{
   int left = 0;
   int mid = 0;
   int right = nums.size();
   while(mid <= right)
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
        right--;
    }
   }
   display(nums); 
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortcolors(nums);
    return 0;
}