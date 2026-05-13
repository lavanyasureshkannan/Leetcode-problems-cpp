#include <iostream>
#include <vector>
using namespace std;

/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

void backtrack(int n, string path, int open, int close, vector<string>& result)
{
    if(path.length() == n*2) 
    {
        result.push_back(path);
        return;
    }  
    if(open < n)
    {
        backtrack(n, path + "(", open+1, close, result);
    }
    if(close < open)
    {
        backtrack(n, path + ")", open, close+1, result);
    }
}

vector<string> generate_paranthesis(int n)
{
    vector<string> result;
    string path;
    backtrack(n, path, 0, 0, result);
    return result;
}

int main()
{
    vector<string> result = generate_paranthesis(3);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}