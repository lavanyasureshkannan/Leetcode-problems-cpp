#include<iostream>
#include<vector>
using namespace std;

/*
    COMBINATIONS -> DECISION TREE + BACKTRACKING
    1. K (n! / (n-k)! k!)
    2. list the number of combination from 0 to n values and the size of decision tree should be k
*/

class Solution
{
    public:
    void backtrack(int n, int k, vector<vector<int>>& result, vector<int> v, int start)
    {
        if(v.size() == k)
        {
            result.push_back(v);
            return;
        }
        // iterate through n
        // Add integer i into the current combination curr.
        //Proceed to add more integers into the combination : backtrack(i + 1, curr).
        ///Backtrack by removing i from curr
        
        for(int i=start; i<=n; i++)
        {
            v.push_back(i);
            backtrack(n,k,result,v,i+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> v; // small array in which you gonna store the combinations[[v1,v2]]
        backtrack(n,k,result,v,1);
        return result;
    }
};


// TC: K.O(N^K)
// SC: O(N^K)



int main()
{
    return 0;
}