#include <iostream>
using namespace std;

/*
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

// main logic window_size - max_freq <= k 

int longest_repeating_char(string s, int k)
{
    int freq[26] = {0};
    int left = 0;
    int N = s.length();
    int maxi = 0;
    int max_freq = 0;
    for(int right=0; right<N; right++)
    {
        // keep track of the frequencies freq[A] - 3
        freq[s[right] - 'A']++;
        // track of freq count 
        max_freq = max(max_freq, freq[s[right] - 'A']); 
        // main logic
        int curr_window = right - left + 1;
        // shrinking the window part
        if((curr_window - max_freq) > k)
        {
            freq[s[left] - 'A'] --;
            left ++;
        }
        maxi = max(maxi, right - left + 1);
    }    
    return maxi;
}

int main()
{
    string s = "ABAB";
    int k = 2;
    cout << longest_repeating_char(s,k);
    return 0;
}