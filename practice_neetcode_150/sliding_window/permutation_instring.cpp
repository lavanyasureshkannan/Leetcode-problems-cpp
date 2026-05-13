#include <iostream>
#include <algorithm>
using namespace std;

/*
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

string sort_string(string s)
{
    sort(s.begin(), s.end());
    return s;
}

bool checkInclusion_sort(string s1, string s2)
{
    int s_l1 = s1.length();
    int s_l2 = s2.length();

    s1 = sort_string(s1);
    for(int i=0; i<=(s_l2 - s_l1); i++)
    {
        if(s1 == sort_string(s2.substr(i, s_l1))) return true;
    }
    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion_sort(s1,s2);
    return 0;
}