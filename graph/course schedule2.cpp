#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// TOPOLOGICAL SORTING -> KHAN'S ALGORIHTM

class Solution
{
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisistes)
    {
        vector<int> result;
        vector<vector<int>> adj_list(numCourses);
        vector<int> indegree(numCourses);
        // forming the adjacenecy list
        for(auto& p : prerequisistes)
        {
            adj_list[p[1]].push_back(pre[0]);
            indegree[p[0]]++;
        }

        // queue
        queue<int> q;
        // start with the courses having no prerequisite
        for(int i=0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            // push that current element which has no pre-requisiste
            result.push_back(curr);

            for(auto neigh_course : adj_list[curr])
            {
                // if there are next course having 0 pre-requiste, then we use it
                if(--indegree[neigh_course] == 0)
                {
                    q.push(neigh_course);
                }
            }
        }
        if(result.size() == numCourses) return result;
        else return {};
    }
};

// TC: O(MxN)
// SC: O(MxN)