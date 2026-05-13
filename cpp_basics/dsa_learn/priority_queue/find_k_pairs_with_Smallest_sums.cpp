#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: 
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/

vector<vector<int>> smallest_sum(vector<int>& nums1, vector<int>& nums2, int k)
{
    vector<int> sums;
    priority_queue<pair<int, pair<int,int>>, 
                    vector<pair<int, pair<int,int>>>,
                    greater<pair<int, pair<int,int>>>> pq;
    for(int i=0; i<nums1.size(); i++)
    {
        int sum = 0;
        for(int j=0; j<nums2.size(); j++)
        {
            sum = nums1[i] + nums2[j];
            pq.push({sum, {nums1[i], nums2[j]}});            
        }
    }
    vector<vector<int>> result;
    for(int i=0; i<k; i++)
    {
        auto top = pq.top();
        result.push_back({top.second.first, top.second.second});
        pq.pop();
    }
    return result;
}

vector<vector<int>> smallest_sum_optimised(vector<int>& nums1, vector<int>& nums2, int k)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = nums1.size();
    int n2 = nums2.size();

    int limit = min(k,n1);
    using P = pair<int, pair<int,int>>;
    priority_queue<P, vector<P>, greater<P>> pq;
    for(int i=0; i<limit; i++)
    {
        int sum = nums1[i] + nums2[0];
        pq.push({sum, {i,0}});
    }
    vector<vector<int>> result;
    while(k > 0 && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int i = top.second.first;
        int j= top.second.second;
        result.push_back({nums1[i], nums2[j]});

        // move to the next index of the same i
        if(j+1 < n2)
        {
            int new_sum = nums1[i] + nums2[j+1];
            pq.push({new_sum, {i, j+1}});
        }
        k --;
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};

    int k = 3;
    // int n1 = nums1.size();
    // int limit = min(k,n1);
    // cout << limit << endl;
    vector<vector<int>> result = smallest_sum_optimised(nums1, nums2, k);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " " ;
        }
        cout << endl;
    }
    // vector<int> sums;
    // priority_queue<pair<int, pair<int,int>>, 
    //                 vector<pair<int, pair<int,int>>>,
    //                 greater<pair<int, pair<int,int>>>> pq;

    // for(int i=0; i<nums1.size(); i++)
    // {
    //     int sum = 0;
    //     for(int j=0; j<nums2.size(); j++)
    //     {
    //         sum = nums1[i] + nums2[j];
    //         pq.push({sum, {nums1[i], nums2[j]}});
    //         //sums.push_back(sum);
            
    //     }
    // }
    // while(!pq.empty())
    // {
    //     auto top_ = pq.top();
    //     int sum = top_.first;
    //     int num1 = top_.second.first;
    //     int num2 = top_.second.second;

    //     cout << sum << ": " << num1 << "," << num2 << endl;  
    //     pq.pop();
    // }

    return 0;
}