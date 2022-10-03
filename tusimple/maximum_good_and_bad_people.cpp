#include<iostream>
#include<vector>
using namespace std;


// DFS + BACKTRACKING
// We explore both possibilities of a person being good or bad
// Finally, we check if current configuration is valid or not

class Solution
{
    public:
    int result = 0;
    int n;

    int maximumGood(vector<vector<int>>& statements)
    {
        n = statements.size();
        string curr = "";
        curr.reserve(n); // reserving the capacity
        dfs(statements, curr, 0, 0);
        return result;
    }

    void dfs(vector<vector<int>>& s, string& curr, int i, int count)
    {
        if(i == n)
        {
            // you will check for validity and update the result to store the maximum good person found till now
            if(valid(s, curr))
            {
                result = max(result, count);
            }
            return;
        }
        curr.append(1, '0');
        // assuming that the ith person is bad
        dfs(s, curr, i+1, count);
        curr.back() = '1'; // 'back' returns the last char in the string
        // assuming that the ith person is good
        dfs(s, curr, i+1, count+1);
        curr.pop_back(); // 'popback' removes the last character in the string decreasing the length by 1

    }


    // checking for the validity of the statements
    bool valid(vector<vector<int>>& s, string& curr)
    {
        for(int i=0; i<n; i++)
        {
            if(curr[i] == '1')
            {
                for(int j=0; j<n; j++)
                {
                    if(s[i][j] != 2 && s[i][j] != curr[j] - '0') return false;
                }
            }
        }
        return true;
    }
};

// TC: 

int main()
{
    string a = "";
    int b = 5;
    a.reserve(5);
    cout << a << endl;

    return 0;
}
