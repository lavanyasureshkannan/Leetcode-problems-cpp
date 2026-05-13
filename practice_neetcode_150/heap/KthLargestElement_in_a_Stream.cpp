#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
k = 3
nums = [4,5,8,2]
add(3) => [4,5,8,2,3] => kth larget 4
add(5) => [8,2,5,5] => kth largest 5
add(10) => [8,2,5,10] => kth largest 5
add(9) => [8,2,9,10] => kth largest 8
add(4) => [2,9,10,4] => kth largest 4

Output: [null, 4, 5, 5, 8, 8]
*/

class Kth_Largest
{
    public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    Kth_Largest(int m_k, vector<int>& nums)
    {
        k = m_k;
        for(int i: nums)
        {
            pq.push(i);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    int add(int val)
    {
        pq.push(val);
        if(pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }

};


int main()
{
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    Kth_Largest kl(k, nums);
    cout << kl.add(3) << endl;
    cout << kl.add(5) << endl;
    cout << kl.add(10) << endl;
    cout << kl.add(9) << endl;
    cout << kl.add(4) << endl;
    return 0;
}