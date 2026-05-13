#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/*
    nums = {5,1,3,9,2,6,8,7,0}
*/

int main()
{
    vector<int> nums = {5,1,3,9,2,6,8,7,0};
    stack <int> st;
    for(int i : nums)
    {
        while(!st.empty() && st.top() < i )
        {
            st.pop();
        }
        st.push(i);   
    }
    
    return 0;
}