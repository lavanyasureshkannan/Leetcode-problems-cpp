#include <iostream>
#include <vector>
using namespace std;


/*
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, 
i.e., [1,2] and [2,1] are considered to be the same combination.
*/

void print(vector<vector<int>>& result)
{
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> result;
void backtrack(int n, int k, vector<int>& sub, int index)
{
    if(sub.size() == k) 
    {
        result.push_back(sub);
    }
    for(int i=index; i<=n; i++)
    {
        sub.push_back(i);
        backtrack(n,k,sub,i+1);
        sub.pop_back();
    }
}
vector<vector<int>> combinations(int n, int k)
{
    vector<int>sub;
    backtrack(n,k,sub,1);
    print(result);
    return result;
}

int main()
{
    combinations(4,2);
    return 0;
}