#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
check for the valid topological order. If exists then true else false
*/

bool Can_Schedule(vector<vector<int>>& prerequisties, int numCourses)
{
    // build an adjacency list
    vector<vector<int>> adj_list (numCourses);

    for(auto &pre : prerequisties)
    {
        int from = pre[0];
        int to = pre[1];
        adj_list[from].push_back(to);
    }
    // calculate the indegree
    vector<int> indegree(numCourses, 0);
    for(int i=0; i<numCourses; i++)
    {
        for(int neigh : adj_list[i])
        {
            indegree[neigh]++;
        }
    }
    // create a queue
    queue<int> q;
    for(int i=0; i<numCourses; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    // pop the q values and reduce in degrees
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);

        for(int neigh: adj_list[front])
        {
            indegree[neigh] --;
            if(indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }

    }
    // check for the valid courses
    if(result.size() == numCourses)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> prerequisties = {{1,0}, {2,0}, {3,1}, {3,2}};
    int n = 4;
    Can_Schedule(prerequisties,n);
    return 0;
}
