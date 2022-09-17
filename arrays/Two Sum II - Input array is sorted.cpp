#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int first = 0;
        int last = numbers.size() - 1;
        while(first< last)
        {
            int sum = numbers[first] + numbers[last];
            if (sum == target)
            {
                return {first+1, last+1};
            }
            else if(sum < target)
            {
                ++first;
            }
            else 
            {
                -- last;
            }
        }
        return {-1,-1};
        
    }
};

// TC: O(N)
// SC: O(1)