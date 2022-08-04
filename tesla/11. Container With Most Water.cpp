#include <iostream>
#include <unordered_set>
using namespace std;

int maxArea(vector<int>& height)
{
    // Approach 1 Brute force approach
    // 1. initialising the maxi
    int maxi = 0;
    // 2. start over the left pointer
    for(int i = 0; i<height.size(); i++)
    {
        // 3. start over the right pointer
        for(int j = i+1; i< height.size(); j++)
        {
            // 4. calculate the current area = min of both the heights * width of both
            int current_area = min(height[i],height[j]) * (j - i);

            // 5. updae the max area
            maxi = max(maxi, current_area);
        } 
    }
    return maxi;
  
}
// TC: O(N^2) 
// SC: O(1) -> because of constant space


int maxArea(vector<int>& height)
{
    // 1. initialise your maxi to zero
    int maxi = 0;
    // 2. initialize your two pointers on both the end
    int left = 0;
    int right = height.size() - 1;
    // 3. loop through the array
    while(left < right)
    {
        // 4. calculate the current area and update the maximum area
        int width = right - left;
        int curr_area = min(height[left], height[right]) * width;
        maxi = max(curr_area, maxi);
        // 5. moving the pointer which hold the greatest value among both
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right ++;
        }

    }
    return maxi;
}
// TC: O(N)
// SC : O(1)
