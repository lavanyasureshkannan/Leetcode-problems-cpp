#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    PRIMS ALGORITHM - One way to construct Minimum Spanning Tree
    1. Maintain visited and non visited
    2. pick a node and choose the minimum weight with its adjacent nodes 
    3. push that to your q and update your weights
    4. repeat till the non-visted gets empty  
*/

class Solution
{
    public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        // inorder to keep track of minimum cost we are gonna use priority queue {weight, curr_element}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // keep track of visited nodes
        vector<bool>visited(n);
        pq.push({0,0});
        int minimum_cost = 0;
        int numOfEdgesUsed = 0;
        while(numOfEdgesUsed < n)
        {
            pair<int,int> curr_element = pq.top();
            pq.pop();
            int weight = curr_element.first;
            int curr_node = curr_element.second;
            // if it is in visted
            if(visited[curr_node])
            {
                continue;
            }
            visited[curr_node] = true;
            minimum_cost = minimum_cost + weight;
            numOfEdgesUsed++;
            // get the adjacenecy node
            for(int nextnode = 0; nextnode < n; nextnode++)
            {
                // if the next node is not in visited push it to pq
                if(!visited[nextnode])
                {
                    int new_weight = abs(points[curr_node][0] - points[nextnode][0]) + 
                                     abs(points[curr_node][1] - points[nextnode][1]);
                    pq.push({new_weight, nextnode});
                }
            }

        }
        return minimum_cost;

    }
};

// TC:Time complexity: O(N2⋅log⁡(N))
// SC: Space complexity: O(N2)

int main()
{
    return 0;
}