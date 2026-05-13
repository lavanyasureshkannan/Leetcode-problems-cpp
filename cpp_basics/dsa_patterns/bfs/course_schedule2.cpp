#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
*/

vector<int> course_Scehdule(vector<vector<int>>& prerequisites, int numCourses)
{
    // vector -> adjacency list
    vector<vector<int>> adjacency_list(numCourses);
    for(auto pre : prerequisites)
    {
        int from = pre[1];
        int to = pre[0];
        adjacency_list[from].push_back(to);
    }

    // calculate the number of indegree
    vector<int> indegree(numCourses,0);
    for(int i=0; i<numCourses; i++)
    {
        for(int neigh : adjacency_list[i])
        {
            indegree[neigh] ++;
        }
    }

    // create a queue and indegree of value 0
    queue<int> q;
    for(int i=0; i<numCourses; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // iterate through queue and add its neighbours
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neigh : adjacency_list[front])
        {
            indegree[neigh] --;
            if(indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    if(result.size() == numCourses) return result;
    else return {};
}

void display(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numCourses = 4;
    vector<int> result = course_Scehdule(prerequisites, numCourses);
    display(result);
    return 0;
}