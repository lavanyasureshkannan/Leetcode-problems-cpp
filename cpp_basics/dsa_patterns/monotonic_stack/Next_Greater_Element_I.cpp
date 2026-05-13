#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

/*
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
*/

vector<int> next_greater_element_bf(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;
    for(int i=0; i<nums1.size(); i++)
    {
        int curr = nums1[i];
        int next_greatear = -1;
        for(int j=0; j<nums2.size(); j++)
        {
            if(nums2[j] == curr)
            {
                for(int k = j+1; k<nums2.size(); k++)
                {
                    if(nums2[k] > curr)
                    {
                        next_greatear = nums2[k];
                        break;
                    }
                }
                break;
            }
        }
        result.push_back(next_greatear); 
    }
    return result;
}

vector<int> next_greater_element_optimised(vector<int>& nums1, vector<int>& nums2)
{
    stack<int> st;
    unordered_map<int, int> mp;
    /*
        map to save the next greater element
        1 -> 3
        3 -> 4
        4 -> -1
        2 -> -1
    */

    for(int i : nums2)
    {
        while(!st.empty() && st.top() < i)
        {
            int top_element = st.top();
            mp[top_element] = i;
            st.pop();
        }
        st.push(i);
    }
    // mp 1->3, 3->4
    // remaining elements
    while(!st.empty())
    {
        int top_element = st.top();
        mp[top_element] = -1;
        st.pop();
    }

    int n = nums1.size();
    vector<int> result;
    result.reserve(n);
    for(int i : nums1)
    {
        result.push_back(mp[i]);
    }
    return result;

}


int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2= {1,3,4,2};
    vector<int> result = next_greater_element_optimised(nums1, nums2);
    // vector<int> result = next_greater_element_bf(nums1, nums2);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}