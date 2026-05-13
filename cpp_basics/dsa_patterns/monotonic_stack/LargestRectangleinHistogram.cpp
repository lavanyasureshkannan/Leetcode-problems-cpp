#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

/*
Input: heights = [2,1,5,6,2,3]
Output: 10
*/

int largest_rect(vector<int>& heights)
{
    int max_area = 0;
    for(int i=0; i<heights.size(); i++)
    {
        int min_height = heights[i];
        for(int j=i; j<heights.size(); j++)
        {
            min_height =  min(min_height, heights[j]);
            int curr_area = min_height * (j-i+1);
            max_area = max(curr_area, max_area);
        }
    }
    return max_area;
}

/*
Refer leetcode explanation video
*/
int largest_rect_stack(vector<int>& heights)
{
    int n = heights.size();
    int max_area = 0;
    stack<int> st;

    for(int i=0; i<n; i++)
    {
        int curr_height;
        if(i == n) curr_height = 0;
        else curr_height = heights[i];

        while(!st.empty() && curr_height < heights[st.top()])
        {
            int curr_val = st.top();
            st.pop();
            int left_index = 0;
            if(st.empty()) { left_index = -1;}
            else left_index = st.top();
            int right_index = i;
            int width = right_index - left_index - 1;
            int curr_area = heights[curr_height] * width;
            max_area = max(curr_area, max_area);
        }
        st.push(i);
    }
    return max_area;
    
}


int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    cout << largest_rect_stack(heights) << endl;
    return 0;
}