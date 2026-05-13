#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: numCourses = 2, prerequisites = [[0,1]]
Output: true
*/

bool course_schedule(vector<vector<int>>& prereq, int numCourses)
{
    // create adj list
    vector<vector<int>> adj_list(numCourses);
    for(auto pre : prereq)
    {
        int from = pre[1];
        int to = pre[0];
        adj_list[from].push_back(to);
    }
    // calculate indegrees
    vector<int> indegrees(numCourses,0);
    for(int i=0; i<numCourses; i++)
    {
        for(auto neigh:adj_list[i])
        {
            indegrees[neigh] ++;
        }
    }
    // create a queue and push indegrees 
    queue<int> q;
    for(int i=0; i<numCourses; i++)
    {
        if(indegrees[i] == 0)
        {
            q.push(i);
        }
    }
    // pop the element from the queue and add the neighbours
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(auto neigh : adj_list[front])
        {
            indegrees[neigh] --;
            if(indegrees[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    if(result.size() == numCourses) return true;
    else return false;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{0,1}};
    cout << course_schedule(prerequisites, numCourses);
    return 0;
}