#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Input: tasks = ["X","X","Y","Y"], n = 2
Output: 5
X -> Y -> idle -> X -> Y.

["A","A","A","B","B","B"] n = 2
A -> B -> Idle -> A -> B -> Idle -> A -> B
o/p = 8
*/

int task_scheduler(vector<char>& tasks, int n)
{
    // count freq => A3 B3
    unordered_map<char, int> mp;
    for(int i=0; i<tasks.size(); i++)
    {
        mp[tasks[i]] ++;
    }
    // map in pq => 3,3
    priority_queue<int> pq;
    for(auto &i:mp)
    {
        pq.push(i.second);
    }
    int time = 0;
    while(!pq.empty())
    {
        int cycle = n + 1;
        vector<int> temp;
        while(cycle > 0 && !pq.empty())
        {
            int count = pq.top();
            pq.pop();
            if(count -1 > 0) 
            {
                temp.push_back(count - 1);
            }
            time ++;
            cycle --;
        }
        for(int i:temp)
        {
            pq.push(i);
        }
        if(!pq.empty()) 
        {
            time += cycle;
        }
    }
    return time;
}
int main()
{
    // vector<char>tasks = {'X','X','Y','Y'};
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << task_scheduler(tasks, n);
    return 0;
}