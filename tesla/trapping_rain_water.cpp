#include<iostream>
#include<vector>
using namespace std;

/*
    1. Two pointer algorithm
    2. left pointer at index 0 and right at the last
    3. move the pointer one by one and calculate the left max and right max
    4. keep track of the water trap by maxleft - height[i] 
    5. If both max left and right are going to be same then it doesnt matter which pointer you move
    6. MOve the left and right pointers based on the minimum leftmax and rightmax val  
*/


class Solution 
{
    public:
    int trap(vector<int>& height)
    {
        int result;
        int left = 0;
        int right = height.size()-1; 

        // keep track of leftmax and rightmax
        int LeftMax = 0;
        int RightMax = 0;

        // base condition
        if(height.size() == 0) return 0;

        // two pointer template
        while(left < right)
        {
            if(height[left] > LeftMax)
            {
                LeftMax = height[left];
            }
            if(height[right] > RightMax)
            {
                RightMax = height[right];
            }
            // moving pointers based on leftmax and rightmax
            if(LeftMax < RightMax)
            {
                result = result + (LeftMax - height[left]);
                left++;
            }
            else
            {
                result = result + (RightMax - height[right]);
                right --;
            }

        }

        return result;
    }
};


int main()
{
    return 0;
}


// TC: O(N) single iteration
// SC: O(1) no additional space