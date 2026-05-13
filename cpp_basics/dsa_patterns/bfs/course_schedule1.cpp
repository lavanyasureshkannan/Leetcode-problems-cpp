#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
*/

bool course_schedule(vector<vector<int>>& prerequisistes, int numCourses)
{
    // 1. vector to adjacency list
    vector<vector<int>> adjacency_list(numCourses);
    for(auto pre: prerequisistes)
    {
        int from = pre[1];
        int to = pre[0];
        adjacency_list[from].push_back(to);
    }
    // calculate the number of indegrees
    vector<int> indegrees(numCourses,0);
    for(int i=0; i<numCourses; i++){
        for(auto neigh : adjacency_list[i]){
            indegrees[neigh] ++;
        }}
    // create a queue and push the indegree whose values are 1
    queue<int> q;
    for(int i=0; i<numCourses; i++)
    {if(indegrees[i] == 0){
            q.push(i);
        }
    }
    // pop the element from q and add their neighbours
    vector<int> result;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neigh : adjacency_list[front])
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
    vector<vector<int>> prereq = {{1,0},{0,1}};
    cout << course_schedule(prereq, 2) << endl;
    return 0;
}