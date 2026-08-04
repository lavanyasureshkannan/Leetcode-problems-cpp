#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Input: s = "OUZODYXAZV", t = "XYZ"
Output: "YXAZ"
*/

string min_window_substring(string s, string t)
{
    int left = 0;
    int right = 0;

    // unordered_map to keep track of target freq
    unordered_map<char, int> target_freq;
    for(int i=0; i<t.length(); i++)
    {
        target_freq[t[i]] ++;
    }

    int min_len = INT_MAX;
    int have = 0;
    int need = target_freq.size();
    int start = 0;
    
    unordered_map<char, int> window_freq;
    while(right < s.length())
    {
        char c = s[right];
        // check if the curr window has the target char
        window_freq[c] ++;
        if(target_freq.count(c) && window_freq[c] == target_freq[c]) have ++;

        while(have == need)
        {
            // since we have have = need update the curr length
            int curr_len = right - left + 1;
            if(curr_len < min_len)
            {
                min_len = curr_len;
                start = left;
            }
            // shirnking part
            char left_c = s[left];
            window_freq[left_c] --;
            if(target_freq.count(left_c) && window_freq[left_c] < target_freq[left_c]) have --;
            left ++;
        }

        right ++;
    }
    if(min_len == INT_MAX) return "";
    else return(s.substr(start, min_len));
}

int main()
{
    string s = "OUZODYXAZV";
    string t = "XYZ";
    cout << min_window_substring(s, t);
    return 0;
}
