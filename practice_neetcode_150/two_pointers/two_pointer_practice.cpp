#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template<typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
}

/***********************************************************************************/
/*
    CONTAINED MOST WATER

    Input: height = [1,7,2,5,4,7,3,6]
    Output: 36
*/
int contained_most_water(vector<int>& height)
{
    if(height.size() == 0) return 0;
    int left = 0;
    int right = height.size() - 1;
    int maxi = 0;
    while(left < right)
    {
        int width = right - left;
        int curr_area = width * min(height[left], height[right]);
        maxi = max(maxi, curr_area);
        if(height[left] < height[right]) left ++;
        else right --;
    }
    return maxi;
}

// TC: O(N)
// SC: O(1)

/***************************************************************************/
/*
    BEST TIME TO BUY AND SELL STOCKS    

    Input: prices = [10,1,5,6,7,1]
    Output: 6
*/
int best_time_to_buy_sell_stocks(vector<int>& prices)
{
    int left = 0;
    int right = 1;
    int max_profit = 0;
    while(right < prices.size())
    {
        if(prices[left] < prices[right])
        {
            int profit = prices[right] - prices[left];
            max_profit = max(max_profit, profit);
        }
        else left ++;
        right ++;
    }
    return max_profit;
}
// TC: O(N)
// SC: O(1)

/*********************************************************************************/
/*
    THREE SUM
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
*/
vector<vector<int>> three_sum_bf(vector<int>& nums)
{
    set<vector<int>> result;
    for(size_t i=0; i<nums.size(); i++)
    {
        for(size_t j=i+1; j<nums.size(); j++)
        {
            for(size_t k=j+1; k<nums.size(); k++)
            {
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    vector<int> levels = {nums[i], nums[j], nums[k]};
                    sort(levels.begin(), levels.end());
                    result.insert(levels);
                }
            }
        }
    }
    return vector<vector<int>> (result.begin(), result.end());
}

vector<vector<int>> three_sum_opti(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i=0; i<nums.size(); i++)
    {
        int left = i+1;
        int right = nums.size() - 1;
        if(i>0 && nums[i] == nums[i-1]) continue;
        while(left < right)
        {
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == 0)
            {
                result.push_back({nums[left], nums[right], nums[i]});
                while(left < right && nums[left] == nums[left+1]) left ++;
                while(left < right && nums[right] == nums[right-1]) right --;
                left++;
                right--;
            }
            else if(sum < 0)
            {
                left ++;
            }
            else
            {
                right --;
            }
        }
    }
    return result;
}
/*******************************************************************************/
/*
    Trapping rain water
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
*/

int trapping_rain_water(vector<int>& heights)
{
    if(heights.size() == 0) return 0;
    int left = 0;
    int right = heights.size() - 1;
    int maxi = 0;
    int left_max = 0;
    int right_max = 0;
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
                maxi += (left_max - heights[left]); 
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
                maxi += (right_max - heights[right]);
            }
            right --;
        }
    }
    return maxi;
}

/***************************************************************************************/
/*
    I/p: numbers = [2,7,11,15], target = 9
    o/p = [1,2]
*/

vector<int> two_pointer_input_sorted(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    
    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target)
        {
            return {nums[left], nums[right]};
        }
        else if(sum < target) { left ++; }
        else right --;
    }
    return {};
}

/***********************************************************************************/
/*
    VALID PALINDROME
    Input: s = "Was it a car or a cat I saw?"
    Output: true
*/

bool valid_palindrome(string s)
{
    string t = "";
    for(char c: s)
    {
        if(isalnum(c))
        {
            t += tolower(c);
        }
    }
    int left = 0;
    int right = t.length() - 1;
    while(left < right)
    {
        if(t[left] == t[right]) return true;
        left ++;
        right --;
    }
    return false;
}

int main()
{
    // vector<int>height ={1,7,2,5,4,7,3,6};
    // Log(contained_most_water(height));

    // vector<int>prices = {10,1,5,6,7,1};
    // Log(best_time_to_buy_sell_stocks(prices));

    // vector<int>nums = {-1,0,1,2,-1,-4};
    // vector<vector<int>> result = three_sum_opti(nums);
    // for(int i=0; i<result.size(); i++)
    // {
    //     for(int j=0; j<result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // Log(trapping_rain_water(height));

    // vector<int> nums = {1,2,3,4};
    // int target = 3;
    // vector<int> result = two_pointer_input_sorted(nums, target);
    // for(int i=0; i<result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }

    Log(valid_palindrome("Was it a car or a cat I saw?"));
    return 0;
}