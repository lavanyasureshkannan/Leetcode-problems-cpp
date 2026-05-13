#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

/*
Input: heights = [2,1,5,6,2,3]
Output: 10
*/

int largest_rectangle_Area_bf(vector<int>& heights)
{
    int maxi = 0;
    for(int i=0; i<heights.size(); i++)
    {
        int min_height = INT_MAX;
        for(int j = i; j<heights.size(); j++)
        {
            min_height = min(heights[j], min_height);
            int curr_area = min_height * (j - i+1); 
            maxi = max(maxi, curr_area);
        }
    }    
    return maxi;
}

int larget_rectangle_area(vector<int>& hieghts)
{
    stack<int> st;
    int maxi = 0;
    int n = hieghts.size();
    for(int i=0; i<=n; i++)
    {
        while(!st.empty() && ((i == n) || hieghts[st.top()] >= hieghts[i]))
        {
            int height = hieghts[st.top()];
            st.pop();

            int width = 0;
            if(st.empty()) width = i;
            else width = i-st.top() - 1;
            maxi = max(maxi, width * height);
        }
        st.push(i);
    }
    return maxi;

}




int main()
{
    vector<int> result = {2,1,5,6,2,3};
    cout << larget_rectangle_area(result);
    return 0;
}