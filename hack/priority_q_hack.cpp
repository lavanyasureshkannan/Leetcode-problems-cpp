#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>,greater<int>> pq_min;
    vector<int>nums = {1,2,3,4,5};
    for(int i:nums)
    {
        pq_min.push(i);
    }
    while(!pq_min.empty())
    {
        cout << pq_min.top() << endl;
        pq_min.pop();
    }
    return 0;
}