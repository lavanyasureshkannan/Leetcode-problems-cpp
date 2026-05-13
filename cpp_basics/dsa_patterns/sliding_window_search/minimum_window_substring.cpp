#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/

string min_window_substring(string s, string t)
{
    string result;
    int left = 0;
    int right = 0;
    int min_len = INT_MAX;

    unordered_map<char, int> target_freq;
    for(int i = 0; i<t.size(); i++)
    {
        target_freq[t[i]] ++;
    }

    unordered_map<char, int> window_freq;
    int have = 0;
    int need = target_freq.size();
    int start = 0;
    while(right < s.length())
    {
        char c = s[right];
        window_freq[c] ++;
        if(target_freq.count(c) && window_freq[c] == target_freq[c]) // have we met the exact requirement for thr char
        {
            have ++;
        }
        while(have == need)
        {
            if((right - left + 1) < min_len)
            {
                min_len = right - left + 1;
                start = left;
            }
            char left_char = s[left];
            window_freq[left_char] --;
            if(target_freq.count(left_char) && window_freq[left_char] < target_freq[left_char])
            {
                have --;
            }
            left ++;
        }
        right ++;
    }
    if(min_len == INT_MAX) return "";
    else return s.substr(start, min_len);
}


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << min_window_substring(s,t);
    return 0;
}