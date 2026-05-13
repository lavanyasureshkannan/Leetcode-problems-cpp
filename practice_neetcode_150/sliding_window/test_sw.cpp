#include <iostream>
using namespace std;

/*
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/


// int longest_repeating(string s, int k)
// {
//     int freq[26] = {0};
//     for(int i=0; i<s.size(); i++)
//     {
//         freq[s[i]] ++;
//     } 

// }

int main()
{
    string s = "ABAB";
    int k = 2;
    int freq[26] = {0};
    int maxi_freq = 0;
    for(int i=0; i<s.size(); i++)
    {
        freq[s[i] - 'A'] ++;
        maxi_freq = max(maxi_freq, freq[s[i] - 'A']);
    } 
    // for(int i=0; i<26; i++)
    // {
    //     cout << freq[i] << endl;
    // }
    cout << maxi_freq;
    return 0;
}