#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution
{
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        int n = points.size(); 
        priority_queue<pair<int, pair<int, int>>> pq; // {key, val} => key - distance and val -> corresponding points
        vector<vector<int>> result;
        for(int i=0; i<points.size(); i++)
        {
            int key = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            // every x1 is gonna be 0 so (3-0)^2 + (4-0)^2 => 3^2 + 4^2 
            pair<int, int> val = {points[i][0], points[i][1]};
            pq.push({key,val});

            // check for the size
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        while(pq.size() > 0)
        {
            auto the_point = pq.top().second; // pair<int,int>
            result.push_back({the_point.first, the_point.second});
            pq.pop();
        }
        return result; 

    }

};


int main()
{
    return 0;
}