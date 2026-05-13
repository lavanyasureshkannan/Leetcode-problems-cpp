#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Input: temperatures = [30,38,30,36,35,40,28]
Output: [1,4,1,2,1,0,0]
*/

vector<int> daily_temp_bf(vector<int>& temperatures)
{
    int n = temperatures.size();
    vector<int> result(n,0);
    for(int i=0; i<temperatures.size(); i++)
    {
        int curr = temperatures[i];
        int count = 0;
        for(int j=i+1; j<temperatures.size(); j++)
        {
            count ++;
            if(temperatures[j] > curr)
            {
                result[i] = count;
                break;
            } 
        }
    }
    return result;
}

vector<int> daily_temp_st(vector<int>& temperatures)
{
    int n = temperatures.size();
    stack<pair<int,int>> st; // [temp, i]
    vector<int> result (n,0);
    for(int i=0; i<temperatures.size(); i++)
    {
        int temp = temperatures[i];
        while(!st.empty() && temperatures[i] > st.top().first)
        {
            auto pair = st.top();
            st.pop();
            result[pair.second] = i - pair.second;
        }
        st.push({temp, i});
    }
    return result;
}


int main()
{
    vector<int> temperatures = {30,38,30,36,35,40,28};
    vector<int> result = daily_temp_st(temperatures);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}