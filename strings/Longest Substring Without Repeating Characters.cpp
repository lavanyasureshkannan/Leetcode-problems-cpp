#include <iostream>
#include <unordered_set>
using namespace std;


// 1. brute force
// 2. sliding window


// BRUTE FORCE
int lengthOfLongestSubstring(string s) 
{
    int result = 0;
    int n = s.length();
    for(int i = 0; i<n; i++) // start indice
    {
        for(int j = i; j<n; j++) // end indice
        {
            if(check_for_repetition(s,i,j))
            {
                result = max(res, j - i + 1); //(end - start + 1)                }
            }
        }
    }
    return result;

}

// check for the repeating characters
// to check for the duplicates we can iterate and put all the characters in unorderd_set 
// and before puting it we check if it contians then return false 
bool check_for_repetition(string& s, int start, int end)
{
    //best ds for checking repeating charaters unordered_set
    unordered_set<char> chars;
    for(int i = start; i<=end; i++)
    {
        char c = s[i];
        if(char.count(c)) // check for the right character 
        {
             return false;
        }
        else 
        {
            chars.insert(c)
        }
    }
    return true;

}
// TC: O(n^3) 
// SC: O(n,m) for unordered set and checking the strings


//SLIDING WINDW CONCEPT
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

// TC: O(2n) -> o(n)
// SC: O(n,m)


// More optimized using unordered map by mapping all the characters to the integers

int main()
{

}