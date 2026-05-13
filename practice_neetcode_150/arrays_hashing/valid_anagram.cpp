#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: s = "racecar", t = "carrace"
Output: true
*/
    
bool valid_anagram(string s, string t)
{
    if(s.size() != t.size()) return false;
    unordered_map<char,int> mp_s;
    for (int i=0; i<s.size(); i++)
    {
        mp_s[s[i]] ++;
    }
    for(int i=0; i<t.size(); i++)
    {
        if(mp_s.find(t[i]) == mp_s.end() || mp_s[t[i]] <= 0) return false;
        else mp_s[t[i]]--;
    }
    return true;
}

int main()
{
    cout << valid_anagram("racecar", "carrace");
    return 0;
}