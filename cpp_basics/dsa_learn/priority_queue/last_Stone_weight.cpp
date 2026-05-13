#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
*/


int last_stone_weight_brute_force(vector<int>& nums)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    while(pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if(x!=y)
        {
            pq.push(y-x);
        }
    }
    if(pq.empty()) return 0;
    else return pq.top();
    
}


int main()
{
    vector<int> nums = {2,7,4,1,8,1};
    cout << last_stone_weight_brute_force(nums) << endl;
    return 0;
}