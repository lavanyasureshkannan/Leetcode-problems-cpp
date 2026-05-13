// Input: s = "Was it a car or a cat I saw?"
// Output: true

#include <iostream>
using namespace std;

bool valid_palindorme(string s)
{
    if (s.empty()) return false;
    string t = " ";
    for(char c: s)
    {
        if(isalnum(c))
        {
            t += tolower(c);
        }
    }
    cout << t << endl;
    int left = 0;
    int right = t.size() - 1;

    while(left < right)
    {
        if(t[left] == t[right]) return true;
        left++;
        right --;
    }
    return false;
}

int main()
{
    string s = "Was it a car or a cat I saw?";
    cout << valid_palindorme(s) << endl;
    return 0;
}