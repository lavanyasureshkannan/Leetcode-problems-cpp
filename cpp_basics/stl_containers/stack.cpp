#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// stack = Last In First Out
int main()
{
    vector<int> nums = {20,40,10,50,30};
    stack<int>st;

    for(int i : nums)
    {
        st.push(i);
    }

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}