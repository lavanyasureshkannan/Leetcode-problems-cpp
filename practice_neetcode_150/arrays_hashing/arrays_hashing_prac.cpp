#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
    CONTAINS DUPLICATES

    Input: nums = [1,2,3,1]
    Output: true

*/
bool contains_duplicates(vector<int>& nums)
{
    unordered_map<int,int> mp;
    for(size_t i=0; i<nums.size(); i++)
    {
        mp[nums[i]] ++;
    }
    for(auto &i : mp)
    {
        if(i.second > 1) return true;
    }
    // sort(nums.begin(), nums.end());
    // for(size_t i=1; i<nums.size(); i++)
    // {
    //     if(nums[i] == nums[i-1]) return true;
    // }
    return false;
}
// TC: O(N) => Hashmap, O(N log n) => sorting
// SC: O(N) => Hashmap, O(1) => sorting 

/*********************************************************************************/
/*
    GROUP ANAGRAMS
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

vector<vector<string>> group_anagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;
    for(size_t i=0; i<strs.size(); i++)
    {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mp[strs[i]].push_back(temp);
    }

    for(auto &i:mp)
    {
        result.push_back(i.second);
    }
    return result;
}

// TC: O(nlogn)
// SC: O(N)

/**********************************************************************************/
/*
    TWO SUMS
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
*/

vector<int> two_sums(vector<int>& nums, int target)
{
    vector<int> result;
    unordered_map<int,int> mp;
    for(size_t i=0; i<nums.size(); i++)
    {
        int search = target - nums[i];
        if(mp.find(search) != mp.end())
        {
            result.push_back(i);
            result.push_back(search);
            return result;
        }
        else
        {
            mp[nums[i]] = i;
        }
    }
    return {};
}

// TC: O(N)
// SC: O(N)

/******************************************************************************/
/*
    Input: s = "anagram", t = "nagaram"
    Output: true
*/

bool valid_anagram(string s, string t)
{
    unordered_map<char,int> mp;
    for(size_t i=0; i<s.size(); i++)
    {
        mp[s[i]] ++;
    }
    for(size_t i=0; i<t.size(); i++)
    {
        if(mp.find(t[i]) == mp.end() || mp[t[i]] <= 0) return false;
        mp[t[i]] --;
    }
    return true;
}


int main()
{
    // vector<int>nums = {1,2,3,1};
    // cout << contains_duplicates(nums) << endl;

    // vector<int>nums = {2,7,11,15};
    // int target = 9;
    // vector<int> result = two_sums(nums,target);
    // for(size_t i=0; i<result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }

    string s = "anagram"; string t = "nagaram";
    cout << valid_anagram(s,t);
    return 0;
}