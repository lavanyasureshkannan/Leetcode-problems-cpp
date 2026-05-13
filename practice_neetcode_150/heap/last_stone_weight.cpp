#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: stones = [2,3,6,2,4]
Output: 1

If x == y, both stones are destroyed
If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

*/

int last_stone_weight(vector<int>& nums)
{
    priority_queue<int> pq_max(nums.begin(), nums.end());
    while(pq_max.size() > 1)
    {
        int y = pq_max.top();
        pq_max.pop();
        int x = pq_max.top();
        pq_max.pop();
        if(x != y)
        {
            pq_max.push(y-x);
        }
    }
    if(pq_max.empty()) return 0;
    else return pq_max.top();
}

int main()
{
    vector<int> stones = {2,3,6,2,4};
    priority_queue<int> pq_max(stones.begin(), stones.end());
    while(!pq_max.empty())
    {
        int top = pq_max.top();
        cout << top << " ";
        pq_max.pop();
    }

    //cout << last_stone_weight(stones) << endl;
    return 0;
}