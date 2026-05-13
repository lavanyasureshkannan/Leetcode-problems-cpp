#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
Input:
["KthLargest", "add", "add", "add", "add", "add"]

[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]
*/

class KthLargest
{
    public:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> pq; 
    KthLargest(int k, vector<int>& nums)
    {
        m_k = k;
        for(int i : nums)
        {
            pq.push(i);
            if(pq.size() > m_k)
            {
                pq.pop();
            }
        }
    }
    int add(int val)
    {
        pq.push(val);
        if(pq.size() > m_k)
        {
            pq.pop();
        }
        return pq.top();   
    }
};


int main()
{
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest kl1(k, nums);
    cout << kl1.add(3) << endl;
    return 0;
}