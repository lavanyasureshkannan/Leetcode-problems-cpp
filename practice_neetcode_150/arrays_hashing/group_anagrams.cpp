#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Input: strs = ["act","pots","tops","cat","stop","hat"]
Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
*/

vector<vector<string>> group_anagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;
    for(int i=0; i<strs.size(); i++)
    {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mp[strs[i]].push_back(temp);
    }
    for (auto i:mp)
    {
        result.push_back(i.second);
    }
    return result;
}

int main()
{
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> result = group_anagrams(strs);
    for (int i=0; i<result.size(); i++)
    {
        for (int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}