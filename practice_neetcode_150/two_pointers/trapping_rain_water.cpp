#include <iostream>
#include <vector>
using namespace std;

/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
*/

/*
KEY LOGIC: min(left_max, right_max)
*/

int trapping_rain_water_bf(vector<int>& heights)
{
    int area = 0;
    for(int i=0; i<heights.size(); i++)
    {
        int left_max = 0;
        int right_max = 0;
        for(int j=i; j>=0; j--)
        {
            left_max = max(left_max, heights[j]);
        }
        for(int j=i; j<heights.size(); j++)
        {
            right_max = max(right_max, heights[j]);
        }
        area += min(right_max, left_max) - heights[i]; 
    }
    return area;
}

// TC: O(N^3)

int trapping_rain_water_two_pointer(vector<int>& heights)
{
    int left = 0;
    int right = heights.size() - 1;
    int left_max = 0;
    int right_max = 0;
    int ans = 0;
    while(left < right)
    {
        if(heights[left] < heights[right])
        {
            if(heights[left] >= left_max)
            {
                left_max = heights[left];
            }
            else
            {
                ans += left_max - heights[left];
            }
            left ++;
        }
        else 
        {
            if(heights[right] >= right_max)
            {
                right_max = heights[right];
            }
            else
            {
                ans += right_max - heights[right];
            }
            right --;
        }
    } 
    return ans;
}

// TC: O(N)


int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapping_rain_water_two_pointer(nums);
    return 0;
}