#include <iostream>
#include <queue>
#include <vector>
using namespace std;


/*
    priority_queue<int> pq_max; // descending
    priority_queue<int, vector<int>, greater<int>> pq_min; // ascending

    conditions:
    if(pq_max.size() > k) pq_max.pop => pops all the max values 
    if(pq_min.size() > k) pq_min.pop => pops all the min values

*/

int main()
{
    vector<int> nums = {4,3,6,1,8,7,11,19,32,24,21};
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    int k = 3;
    for(int i: nums)
    {
        // pq_max.push(i);
        pq_max.push(i);
        if(pq_max.size() > k) 
        {
            pq_max.pop();
        }
    }
    while(!pq_max.empty())
    {
        int top = pq_max.top();
        cout << top << " ";
        pq_max.pop();
    }
    return 0;
}