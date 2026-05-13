#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
*/

vector<int> course_schedule2(vector<vector<int>>& prerequisite, int numCourses)
{
    // 1. create an adjacency_list 
    vector<vector<int>> adjacency_list(numCourses);
    for(auto pre : prerequisite)
    {
        int from = pre[1];
        int to = pre[0];
        adjacency_list[from].push_back(to);
    }

    // 2. calculate the indegrees
    vector<int> indegrees(numCourses,0);
    for(int i=0; i<numCourses; i++)
    {
        for(int neigh:adjacency_list[i])
        {
            indegrees[neigh] ++;
        }
    }

    // 3. create a queue
    queue<int> q;
    for(int i=0; i<numCourses; i++)
    {
        if(indegrees[i] == 0)
        {
            q.push(i);
        }
    }

    // 4. pop everything one by one and push the neigh
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neigh:adjacency_list[front])
        {
            indegrees[neigh] --;
            if(indegrees[neigh] == 0)
            {
                q.push(neigh);
            }
       }
    }
    if(result.size() == numCourses) return result;
    else return {};

}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result = course_schedule2(prerequisites, numCourses);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}