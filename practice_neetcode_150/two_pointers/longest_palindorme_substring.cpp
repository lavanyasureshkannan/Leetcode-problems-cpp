#include <iostream>
using namespace std;


/*
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
*/

bool is_palindrome(string s, int i, int j)
{
    int left = i;
    int right = j-1;
    while(left < right)
    {
        if(s[left] != s[right]) return false;
        left ++;
        right --;
    }
    return true;
}

string longest_palindrome(string s)
{
    for(size_t len=s.length(); len>0; len--)
    {
        for(size_t start=0; start+len <= s.length(); start++) // every string is using starting point as its length
        {
            if(is_palindrome(s,start,start+len))
            {
                return s.substr(start,len);
            }
        }
    }
    return "";
}

int main()
{
    string s = "babad";
    cout << longest_palindrome(s) << endl;
    return 0;
}