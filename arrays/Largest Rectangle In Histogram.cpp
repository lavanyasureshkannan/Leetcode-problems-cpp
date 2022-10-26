#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;


// Instead of taking every possible pair and then finding the bar of minimum height lying between them everytime, we can find the bar of minimum height for current pair by using the minimum height bar of the previous pair.

// In mathematical terms, minheight=min⁡(minheight,heights(j))minheight=\min(minheight, heights(j))minheight=min(minheight,heights(j)), where heights(j)heights(j)heights(j) refers to the height of the jjjth bar.



class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        size_t max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) 
        {
            int min_height = INT_MAX;
            for (size_t j = i; j < heights.size(); j++) 
            {
                min_height = min(min_height, heights[j]);
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }
};