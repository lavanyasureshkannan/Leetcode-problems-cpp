#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/

vector<int> daily_temp_bf(vector<int>& temperatures)
{
    int n = temperatures.size();
    vector<int> result(n,0);
    for(int i = 0; i<temperatures.size(); i++)
    {
        int curr = temperatures[i];
        int temp = 0;
        for(int j=i+1; j<temperatures.size(); j++)
        {
            temp ++;
            if(temperatures[j] > curr)
            {
                result[i] = temp;
                break;
            }
        }
    }
    return result;
}

vector<int> daily_temperatures_optmised(vector<int>& temperatures)
{
    stack<int> st;
    int n = temperatures.size();
    vector<int> result(n,0);
    for(int i=0; i < temperatures.size(); i++)
    {
        while(!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int j = st.top();
            st.pop();
            result[j] = i-j;
        }
        st.push(i);
    }
    return result;
}


int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = daily_temperatures_optmised(temperatures);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}