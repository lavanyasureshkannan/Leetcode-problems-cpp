#include <iostream>
#include <unordered_set>
using namespace std;

/*
Input: s = "zxyzxyz"
Output: 3
*/

int longest_substr_wo_repeating_char(string s)
{
    unordered_set<char> char_ss;
    int left = 0;
    int right = 0;
    int maxi = 0;
    while(right < s.size())
    {
        if(char_ss.find(s[right]) == char_ss.end())
        {
            char_ss.insert(s[right]);
            right ++;
            maxi = max(maxi, right - left);
        }
        else 
        {
            char_ss.erase(s[left]);
            left ++;
        }
    }
    return maxi;
}

int main()
{
    string s = "zxyzxyz";
    cout << longest_substr_wo_repeating_char(s) << endl;
    return 0;
}