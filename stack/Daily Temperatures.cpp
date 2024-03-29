#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
       
        int n = temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(0);
        
        for(int i = 0; i<n; i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

// TC: O(N)
// SC: O(N) 