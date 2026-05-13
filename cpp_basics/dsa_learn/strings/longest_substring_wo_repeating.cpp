#include <iostream>
#include <unordered_set>
using namespace std;

/*
Input: s = "abcabcbb"
Output: 3
*/

int longest_substring_wo_repeating_char(string s)
{
    int left = 0;
    int right = 0;
    int result = 0;
    unordered_set<char> char_ss;
    while(right < s.length())
    {
        if(char_ss.find(s[right]) == char_ss.end()) // didnot find the element
        {
            char_ss.insert(s[right]);
            right ++;
            result = max(result, right - left);
        }
        else
        {
            char_ss.erase(s[left]);
            left ++;
        }
    }
    return result;
}

int main()
{
    string s = "abcabcbb";
    cout << longest_substring_wo_repeating_char(s) << endl;
    return 0;
}