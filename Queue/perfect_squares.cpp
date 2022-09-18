#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution 
{
public:
    int numSquares(int n)
    {
        int count = 1;
        unordered_set<int>visited;
        queue<int>Q;
        
        Q.push(0);
        visited.insert(0);
        
        while(!Q.empty())
        {
            int size = Q.size();
            for(int i = 0;i<size; i++)
            {
                int top = Q.front();
                Q.pop();
                for(int j = 1; j*j <= n; j++)
                {
                    int curr_element  = top + (j*j);
                    if(curr_element == n) 
                    {
                        return count;
                        cout<< count;
                    }
                    else if(curr_element > n)
                    {
                        break;
                    }
                    else if(visited.find(curr_element) == visited.end())
                    {
                        Q.push(curr_element);
                        visited.insert(curr_element);
                    }
                }
            }
            count++;
            
        }
        return count;
    }
};
//  TIME COMPLEXITY O(N^2)
// SC :O(m,n)
