#include <iostream>
#include <unordered_set>
using namespace std;

/*
Input: s = "abcabcbb"
Output: 3
*/

int longest_substring_wo_repeating(string s)
{
    int left = 0;
    int right = 0;
    int maxi = 0;
    unordered_set<char> chars;
    while(right < s.length())
    {
        if(chars.find(s[right]) == chars.end())
        {
            chars.insert(s[right]);
            right ++;
            maxi = max(maxi, (right - left));
        }
        else
        {
            chars.erase(s[left]);
            left ++;
        }
    }
    return maxi;
}

int main()
{
    string s = "abcabcbb";
    cout << longest_substring_wo_repeating(s) << endl;
    return 0;
}

