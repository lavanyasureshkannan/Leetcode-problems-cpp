#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    k freq element
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

*/

vector<int> k_freq_elements(vector<int>& nums, int k)
{
    unordered_map<int,int> mp;
    for(size_t i =0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_min;
    for(auto &i : mp)
    {
        pq_min.push({i.first, i.second});
    }
    while(pq_min.size() > k)
    {
        pq_min.pop();
    }
    vector<int> result;
    while(pq_min.size() > 0)
    {
        result.push_back(pq_min.top().second);
        pq_min.pop();
    }
    return result;
}

/************************************************************************************/
/*
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5
*/

int kthlargest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq_min;
    for(int i=0; i<nums.size(); i++)
    {
        pq_min.push(nums[i]);
    }  
    while(pq_min.size() > k)
    {
        pq_min.pop();
    }
    return pq_min.top();
}

/************************************************************************************/
/*
    kth largest element in the stream
    
    ["KthLargest", "add", "add", "add", "add", "add"]
    [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

    Output: [null, 4, 5, 5, 8, 8]
*/

class kthLargest
{
    public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    kthLargest(int m_k, vector<int>& nums)
    {
        k = m_k;
        for(auto &i: nums)
        {
            pq.push(i);
        }
        if(pq.size() > m_k)
        {
            pq.pop();
        }

    }
    int add(int val)
    {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/*************************************************************************************/
/*
    k closest point to the origin
    Input: points = [[1,3],[-2,2]], k = 1
    Output: [[-2,2]]
*/

vector<vector<int>> k_closest_points(vector<vector<int>>& points, int k)
{
    // base case
    if(points.size() == 0) return {};
    if(k == 0) return points;
    // {distance, {point 1, point 2}}
    priority_queue<pair<int,pair<int,int>>> pq;
    for(size_t i=0; i<points.size(); i++)
    {
        int distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        int point_1 = points[i][0];
        int point_2 = points[i][1];
        pq.push({distance, {point_1,point_2}});
        while(pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<vector<int>> result;
    while(!pq.empty())
    {
        auto top = pq.top();
        result.push_back({top.second.first, top.second.second});
        pq.pop();
    }
    return result;
}

// TC: O(n log k) => o(n) for looping and o(log k) for heap insert
// SC: O(K) => heap

/*****************************************************************************/
/*
    Last stone weight
    Input: stones = [2,7,4,1,8,1]
    Output: 1
*/

int last_stone_weight(vector<int>& stones)
{
    priority_queue<int> pq(stones.begin(), stones.end());
    while(pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if(x != y) 
        {
            pq.push(y-x);
        }
    }
    if(pq.empty()) return 0;
    else return pq.top();
}
// TC: O(N)
// SC: O(k)

/*************************************************************************************/
/*
    Find_median_from_data_stream
    Input
    ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    [[], [1], [2], [], [3], []]
    Output
    [null, null, null, 1.5, null, 2.0]
*/

class MedianFinder
{
    public:
    MedianFinder() {};
    priority_queue <double> left; // max_heap
    priority_queue <double, vector<double>, greater<double>> right; // min_heap
    
    void addNum(double val)
    {
        left.push(val);
        right.push(left.top());
        left.pop();
        // maintain balance
        if(right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
    } 

    double calculate_median() const
    {
        if(left.empty()) return 0.0;
        double result = 0.0;
        if(left.size() == right.size())
        {
            double l = left.top();
            double r = right.top();
            result = (l + r) / 2.0;
            return result;
        }
        else return left.top();
    }
};

/*******************************************************************************/
/*
    task scheduler
    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    A -> B -> idle -> A -> B -> idle -> A -> B.
*/

int task_scheduler(vector<char>& tasks, int n)
{
    unordered_map<char,int> mp;
    for(size_t i = 0; i<tasks.size(); i++)
    {
        mp[tasks[i]] ++;
    }
    priority_queue<int> pq;
    for(auto &i : mp)
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
            int curr = pq.top(); // 3
            pq.pop();
            if(curr - 1 > 0)
            {
                temp.push_back(curr - 1);
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
    // vector<int>nums = {1,1,1,2,2,3};
    // int k = 2;

    // vector<int>nums = {3,2,1,5,6,4};
    // int k = 2;
    // cout << kthlargest(nums,k);

    // int k = 3;
    // vector<int> nums = {4, 5, 8, 2};
    // kthLargest kl(k, nums);
    // cout << kl.add(3) << endl;
    // cout << kl.add(5) << endl;
    // cout << kl.add(10) << endl;
    // cout << kl.add(9) << endl;
    // cout << kl.add(4) << endl;

    // vector<vector<int>>points {{1,3},{-2,2}};
    // int k = 1;
    // vector<vector<int>> result = k_closest_points(points,k);
    // for(size_t i=0; i<result.size(); i++)
    // {
    //     for(size_t j=0; j<result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     } 
    //     cout << endl;
    // }

    // vector<int> stones = {2,7,4,1,8,1};
    // cout << last_stone_weight(stones);

    // MedianFinder Mfpq1;
    // Mfpq1.addNum(1);
    // cout << Mfpq1.calculate_median() << endl;
    // Mfpq1.addNum(3);
    // cout << Mfpq1.calculate_median() << endl;
    // Mfpq1.addNum(2);
    // cout << Mfpq1.calculate_median() << endl;

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << task_scheduler(tasks, n);

    return 0;
}