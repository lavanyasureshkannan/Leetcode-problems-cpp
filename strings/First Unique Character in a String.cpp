#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


// APPROACH 1
// 1. creating a count of array ranges from 0 to 26
// 2. subtracting the ascii value of each string from a and storing its frequency 
// 3. Iterating again to check if the frequency (count) == 1 and returning that particular index.
class Solution 
{
    public:
    int firstUniqChar(string s) 
    {
        int count[26] ={0};
        //vector <int> count (26,0);
        for(int i = 0; i<s.size(); i++)
        {
            count[s[i] - 'a'] +=1;
        }
        for(int i = 0; i<s.length(); i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};


// TC: O(N)
// SC: O(1)

class Solution
{
    public:
    int firstUniqChar(string s)
{
    unordered_map<int,int> mp;
    for(int i=0; i<s.size(); i++)
    {
        mp[s[i]]++;
    }
    for(int i=0; i<s.size(); i++)
    {
        if(mp[s[i]] == 1) return i;
    }
    return -1;

}
};

// TC: O(N)
// SC: O(1)