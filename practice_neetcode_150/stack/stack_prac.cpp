#include <iostream>
#include <vector> 
#include <stack>
using namespace std;

/*
    DAILY TEMPERATURES
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
*/

vector<int> daily_temperatures(vector<int>& temps)
{
    int n = temps.size();
    vector<int> result(n,0);
    stack<int> st;
    for(size_t i=0; i<temps.size(); i++)
    {
        while(!st.empty() && temps[i] > temps[st.top()])
        {
            int top = st.top();
            st.pop();
            result[top] = i-top;
        }
        st.push(i);
    }
    return result;
}

/**********************************************************************/
/*
    Input: heights = [2,1,5,6,2,3]
    Output: 10 
*/

int height_histogram(vector<int>& heights)
{
    if(heights.size() == 0) return 0;
    stack<int>st;
    int maxi = 0;
    for(size_t i=0; i<heights.size(); i++)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int width = 0;
            if(st.empty()) width = i; // if stack is empty
            else width = i- st.top() - 1;
            maxi = max(maxi, width * height);
        }
        st.push(i);
    }
    return maxi;
}

/**********************************************************************************/
/*
    VALID PARANTHESIS
    Input: s = "()[]{}"
    Output: true
*/

bool valid_paranthesis(string s)
{
    stack<int> st;
    for(size_t i=0; i<s.size(); i++)
    {
        char c = s[i];
        if(c == '(') st.push(')');
        else if(c == '[') st.push(']');
        else if(c == '{') st.push('}');
        else if(!st.empty() && (c == st.top()) ) st.pop();
        else return false;
    }
    return st.empty();
}


int main()
{
    // vector<int>temperatures = {73,74,75,71,69,72,76,73};
    // vector<int> result = daily_temperatures(temperatures);
    // for(size_t i=0; i<result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    // vector<int>heights = {2,1,5,6,2,3};
    // cout << height_histogram(heights) << endl;

    string s = "()[]{}";
    cout << valid_paranthesis(s) << endl;
    return 0;

}