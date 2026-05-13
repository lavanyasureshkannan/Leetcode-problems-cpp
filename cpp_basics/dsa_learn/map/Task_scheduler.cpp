#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. 
The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
*/

int task_scheduler_bf(vector<char>& tasks, int n)
{
    // count the number of freq
    unordered_map<char,int> freq_mp;
    if(n == 1) return tasks.size();
    for(int i=0; i<tasks.size(); i++)
    {
        freq_mp[tasks[i]]++;
    }
    // fint the max freq
    int max_freq = 0;
    for(auto &i : freq_mp)
    {
        max_freq = max(i.second, max_freq);
    }
    // count_max
    int coun_max_freq = 0;
    for(auto &i: freq_mp)
    {
        if(i.second == max_freq)
        {
            coun_max_freq ++;
        }
    }
    // interval calc
    int interval = (max_freq -1) * (n+1) + coun_max_freq;
    return interval;

}

void print(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int task_scheduler_heap(vector<char>& tasks, int n)
{
    unordered_map<char,int> freq_mp;
    for(int i=0; i<tasks.size(); i++)
    {
        freq_mp[tasks[i]]++;
    }
    priority_queue<int> pq;
    for(auto &i : freq_mp)
    {
        pq.push(i.second);
    }
    int time = 0;
    while(!pq.empty())
    {
        int cycle = n+1;
        vector<int> temp; // we cannot push pq immediately back to the map
        // ex A-3 after a cycle A-2 now if we push it back to PQ priority agian beocmes A
        // we need a cooling period. That is why we need temp
        while(cycle > 0 && !pq.empty())
        {
            int count = pq.top();
            pq.pop(); 
            if(count - 1 > 0) temp.push_back(count - 1);
            time ++;
            cycle --;
        }
        for(int remaining : temp)
        {
            pq.push(remaining);
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
    vector<char>tasks = {'A','A','A', 'B','B','B'};
    int n = 3;
    cout << task_scheduler_heap(tasks,n);
    return 0;
}
