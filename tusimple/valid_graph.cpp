#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;


bool validTree(int n, vector<vector<int>>& edges) 
{
        // base case
        if(n < 1)
        {
            return false;
        }
        vector<vector<int>> Graph(n, vector<int>(n,0));        
        for(auto v : edges)
        {
            Graph[v[0]][v[1]] = 1;
            Graph[v[1]][v[0]] = 1;
        }
        
        set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        
        bool flag = false;        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(int i = 0; i< n; i++)
            {
                if(Graph[curr][i])
                {
                    if(visited.count(i))
                    {
                        flag = true;                    
                    }
                    else
                    {
                        Graph[curr][i] = Graph[i][curr] = 0;          
                        q.push(i);
                        visited.insert(i);
                    }
                }                
            }            
        }
        return (visited.size() == n && !flag);
    }