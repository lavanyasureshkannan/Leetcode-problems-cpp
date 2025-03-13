#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

// BRUTE FORCE

class solution
{
    public:
    int longestsubstring(string& s)
    {
        int result;
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i; j<s.size(); j++)
            {
                if(check(s,i,j))
                {
                    result = max(result, j-i+1);
                }
            }
        }
        return result;
    }

    bool check(string& s, int start, int end)
    {
        unordered_set<char> chars;
        for(int i = start; i <= end; i++)
        {
            char c = s[i];
            // if the char already exist then return false
            if(chars.count(c))
            {
                return false;
            }
            chars.insert(c);
        }
        return true;
    }
};
// TC: O(n^3) 
// SC: O(n) -> unordered_set

//***************************************************************************************************************************

// two pointer approach

class Solution
{
    public:
    int longestsubstring(string& s)
    {
        unordered_map<char, int> chars;
        int result = 0;
        int left = 0;
        int right =0;
        while (right < s.size())
        {
            char right_char = s[right];
            chars[right_char]++;
            while(chars[right_char] > 1)
            {
                char left_char = s[left];
                chars[left_char]--;
                left++;
            }
            result = max(result, right - left + 1); 
        }
        return result;
    }
};
// TC: O(2n)
// SC: O(m)

//************************************************************************************************************************

class Solution
{
    public:
    int longestsubstring(string& s)
    {
        int result;
        unordered_map<char, int> mp;
        int i=0;
        // extedning the range of i and j
        for(int j=0; j<s.size(); j++)
        {
            if(mp[s[j]] > 0)
            {
                i = max(mp[s[j]],i);
            }
            result = max(result, j-i+1);
            mp[s[j]] = j+1;
        }
    }
};

// TC: O(n)
// SC: O(n)


//*****************************************************************

class Solution 
{
public:
int lengthOfLongestSubstring(string s) 
{
    int left = 0;
    int right = 0;
    int maxi = 0;

    unordered_set <char> chars;

    // right will reach the end first
    while(right < s.length())
    {
        //insert the characters inside unorderedset
        if(chars.find(s[right]) == chars.end())
        {
            chars.insert(s[right]);
            right ++;
            maxi = max(maxi, (right - left));
        }
        else
        {
            // the window will pop the previously seen char 
            // for ex : abcabcdd --> left = a right ++ 
            // if right sees the character then it is popped out of the set
            chars.erase(s[left]);
            left++;
        }

    }
    return maxi;
}

};


// recent approach

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;


// a    b   c   a   b   c   b   b
// lr
// l    r
// 
int longest_Repeating_substring(string s)
{
    int left = 0;
    int right = 0;
    int maxi_return = 0;
    unordered_set<char> char_ss;
    while(right < s.size())
    {
        if(char_ss.find(s[right]) == char_ss.end())
        {
            char_ss.insert(s[right]);
            maxi_return = max(maxi_return, (right - left + 1));
            right ++;
        }
        else
        {
            char_ss.erase(s[left]);
            left ++;
        }
    }
    return maxi_return;

}

// O(N)
// O(1)

int main()
{
    string ss = "abcabcbb";
    cout << longest_Repeating_substring(ss);
    return 0;
}

int main()
{
    solution s;
    string test = "abcabcbb";
    cout << s.longestsubstring(test);
    return 0;
}
